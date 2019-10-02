#include "Game.h"
#include <iostream>

Game::Game(const sf::VideoMode videoMode, const std::string& title)
	: mWindow(videoMode, title)
{
	mAsteroidCooldown = Entity::RandomizeRangef(EntityFactory::GetAsteroidCld().x, EntityFactory::GetAsteroidCld().y);
	mCoinCooldown = Entity::RandomizeRangef(EntityFactory::GetCoinCld().x, EntityFactory::GetCoinCld().y);
}

Game::~Game()
{
	for (Entity* e : mEntities)
	{
		delete e;
	}
	mEntities.clear();
}


void Game::Init()
{
	srand((unsigned int)time(nullptr));
	
	mWindow.setVerticalSyncEnabled(true);
	
	mEntities.push_back(mFactory.CreatePlayer());
}

void Game::Run()
{
	while (mWindow.isOpen())
	{
		sf::Event event;
		while (mWindow.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				mWindow.close();
		}

		Update();
		Render();
	}
}

void Game::Update()
{

	for (int i = 0; i < mEntities.size(); i++)
	{
		mEntities[i]->Update();
		RemoveDead(i);
	}

	SpawnAsteroid(EntityFactory::GetAsteroidCld().x, EntityFactory::GetAsteroidCld().y);
	SpawnCoin(EntityFactory::GetCoinCld().x, EntityFactory::GetCoinCld().y);

	CollisionManagement();
}

void Game::Render()
{
	mWindow.clear(sf::Color::Black);
	
	for (Entity* e : mEntities)
	{
		mWindow.draw(*e->GetSprite());
	}
	
	mWindow.display();
}


sf::RenderWindow& Game::GetRenderWindow()
{
	return mWindow;
}


void Game::SpawnAsteroid(const float min, const float max)
{
	if (mAsteroidClock.getElapsedTime().asSeconds() >= mAsteroidCooldown)
	{
		mEntities.push_back(mFactory.CreateAsteroid());
		mAsteroidCooldown = Entity::RandomizeRangef(EntityFactory::GetAsteroidCld());
		mAsteroidClock.restart();
	}
}

void Game::SpawnCoin(const float min, const float max)
{	
	if (mCoinClock.getElapsedTime().asSeconds() >= mCoinCooldown)
	{
		mEntities.push_back(mFactory.CreateCoin());
		mCoinCooldown= Entity::RandomizeRangef(EntityFactory::GetCoinCld());
		mCoinClock.restart();
	}
}

void Game::RemoveDead(int i)
{
	if (!mEntities[i]->IsAlive())
	{
		delete mEntities[i];
		mEntities.erase(mEntities.begin() + i);
	}
}

bool Game::CollisionManagement()
{
	Entity* player = nullptr;
		
	while (player == nullptr)
	{
		for (Entity* e : mEntities)
		{
			if (e->GetType() == PlayerType)
			{
				player = e;
			}
		}
		if (player == nullptr)
		{
			std::cout << "ERROR: There is no player!\n";
			return false;
		}		
	}

	for (Entity* e : mEntities)
	{
		// Test if collision unless it's PlayerType.
		// PlayerType is always false		
		if (e->GetType() == EnemyType && CollisionDetection(player, e))
		{
			mWindow.close();
		}
		else if (e->GetType() == PickupType && CollisionDetection(player, e))
		{
			e->Kill();
		}
	}

	return true;
}

bool Game::CollisionDetection(Entity* player, Entity* other)
{
	float xPlayer = player->GetPosition().x;
	float yPlayer = player->GetPosition().y;

	float xOther = other->GetPosition().x;
	float yOther = other->GetPosition().y;

	float xDist = xPlayer - xOther;
	float yDist = yPlayer - yOther;

	float minCollisionDist = player->GetRadius() + other->GetRadius();

	float distance = sqrtf(powf(xDist, 2) + powf(yDist, 2));

	return distance < minCollisionDist ? true : false;
}

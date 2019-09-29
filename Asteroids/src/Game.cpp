#include "Game.h"

Game::Game(const sf::VideoMode videoMode, const std::string& title)
	: mWindow(videoMode, title)
{
}

Game::~Game()
{
	for (Entity* e : mEntities)
	{
		delete e;
	}
	mEntities.clear();
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
	for (Entity* e : mEntities)
	{
		e->Update();
	}

	SpawnAsteroid(Asteroid::SPAWN_COOLDOWN);
	SpawnCoin(Coin::SPAWN_COOLDOWN);
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

void Game::Init()
{
	mWindow.setVerticalSyncEnabled(true);
	
	mEntities.push_back(mFactory.CreatePlayer());
}

sf::RenderWindow& Game::GetRenderWindow()
{
	return mWindow;
}

void Game::SpawnAsteroid(float cooldown)
{
	if (mAsteroidClock.getElapsedTime().asSeconds() >= cooldown)
	{
		mEntities.push_back(mFactory.CreateAsteroid());
		mAsteroidClock.restart();
	}
}

void Game::SpawnCoin(float cooldown)
{
	if (mCoinClock.getElapsedTime().asSeconds() >= cooldown)
	{
		mEntities.push_back(mFactory.CreateCoin());
		mCoinClock.restart();
	}
}

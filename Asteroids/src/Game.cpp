#include "Game.h"
#include "EntityManager.h"

Game::Game(const sf::VideoMode videoMode, const std::string& title)
	: mWindow(videoMode, title)
{
	EntityManager<Player> manager{"player.png", [](const sf::Texture& tex)->Player
	{
		return Player(tex);
	}};





	manager.newEntity();
}

Game::~Game()
{
	for (Entity* e : mEntities)
	{
		delete mEntities[0];
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
}

void Game::Render()
{
	mWindow.clear(sf::Color::Black);
	
	for (Entity* e : mEntities)
	{
		mWindow.draw(e->GetSprite());
	}
	
	mWindow.display();
}

void Game::Init()
{
	mWindow.setVerticalSyncEnabled(true);
	
	Player::Init("ShipSprite.psd");

	mEntities.push_back(new Player(sf::Vector2f(400, 300)));
}

sf::RenderWindow& Game::GetRenderWindow()
{
	return mWindow;
}

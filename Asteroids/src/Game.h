#pragma once

#include "Entity.h"
#include <vector>
#include "EntityFactory.h"

class Game
{
public:
	Game(sf::VideoMode videoMode, const std::string& title);
	~Game();

	void Init();
	void Run();

	sf::RenderWindow& GetRenderWindow();

private:
	void Update();
	void Render();
	
	void SpawnAsteroid(float cooldown);
	void SpawnCoin(float cooldown);
	void RemoveDead(int i);
	
private:
	typedef std::vector<Entity*> entities_t;

	EntityFactory mFactory;
	entities_t mEntities;

	sf::RenderWindow mWindow;
	sf::Clock mAsteroidClock;
	sf::Clock mCoinClock;
};


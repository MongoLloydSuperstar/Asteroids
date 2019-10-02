#pragma once

#include <vector>

#include "Entity.h"
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
	
	void SpawnAsteroid(float min, float max);
	void SpawnCoin(float min, float max);
	void RemoveDead(int i);

	bool CollisionManagement();
	bool CollisionDetection(Entity* player, Entity* other);

private:
	typedef std::vector<Entity*> entities_t;

	EntityFactory mFactory;
	entities_t mEntities;

	sf::RenderWindow mWindow;
	sf::Clock mAsteroidClock;
	sf::Clock mCoinClock;

	float mAsteroidCooldown, mCoinCooldown;
};


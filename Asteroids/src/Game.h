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
	struct Cooldown
	{
		Cooldown(float min, float max)
			: min(min), max(max)
		{}

		float GetRandom()
		{
			
		}
		
		
		float min, max;
	};
	
	void Update();
	void Render();
	
	void SpawnAsteroid(float min, float max);
	void SpawnCoin(float min, float max);
	void RandomizeCooldown(Cooldown& cooldown);
	void RemoveDead(int i);
	
private:
	typedef std::vector<Entity*> entities_t;

	EntityFactory mFactory;
	entities_t mEntities;

	sf::RenderWindow mWindow;
	sf::Clock mAsteroidClock;
	sf::Clock mCoinClock;

	Cooldown mAsteroidCDRange, mCoinCDRange;
};


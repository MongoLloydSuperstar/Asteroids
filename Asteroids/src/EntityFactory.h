#pragma once
#include "Player.h"
#include "Asteroid.h"
#include "Coin.h"

class EntityFactory
{
public:
	EntityFactory();
	~EntityFactory() = default;
	
	Entity* CreatePlayer();
	Entity* CreateAsteroid();
	Entity* CreateCoin();
	

private:
	Player* mPlayer;
	Asteroid* mAsteroid;
	Coin* mCoin;
};



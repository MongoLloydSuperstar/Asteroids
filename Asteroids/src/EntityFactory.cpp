#include "EntityFactory.h"

EntityFactory::EntityFactory()
{
	mPlayer = new Player;
	mAsteroid = new Asteroid;
	mCoin = new Coin;
}

Entity* EntityFactory::CreatePlayer()
{
	Entity* p = new Player(*mPlayer);
		
	return p;
}

Entity* EntityFactory::CreateAsteroid()
{
	Entity* p = new Asteroid(*mAsteroid);

	return p;
}

Entity* EntityFactory::CreateCoin()
{
	Entity* p = new Coin(*mCoin);

	return p;
}

#include "EntityFactory.h"
#include "Player.h"
#include "Asteroid.h"
#include "Coin.h"
#include <iostream>


EntityFactory::EntityFactory()
{
	if (!mPlayerTexture.loadFromFile(Player::FILENAME))
	{
		std::cout << "Asteroid: Couldn't load texture!\n";
	}
	if (!mAsteroidTexture.loadFromFile(Asteroid::FILENAME))
	{
		std::cout << "Asteroid: Couldn't load texture!\n";
	}
	if (!mCoinTexture.loadFromFile(Coin::FILENAME))
	{
		std::cout << "Asteroid: Couldn't load texture!\n";
	}
	
	mPlayer = new Player(mPlayerTexture);
	mAsteroid = new Asteroid(mAsteroidTexture);
	mCoin = new Coin(mCoinTexture);
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

sf::Vector2f EntityFactory::GetAsteroidCld()
{
	return Asteroid::SPAWN_COOLDOWN;
}

sf::Vector2f EntityFactory::GetCoinCld()
{
	return Coin::SPAWN_COOLDOWN;
}

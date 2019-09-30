#pragma once
#include <SFML/Graphics/Texture.hpp>

class Entity;
class Player;
class Asteroid;
class Coin;

class EntityFactory
{
public:
	EntityFactory();
	~EntityFactory() = default;
	
	Entity* CreatePlayer();
	Entity* CreateAsteroid();
	Entity* CreateCoin();

	static sf::Vector2f GetAsteroidCld();
	static sf::Vector2f GetCoinCld();
	

private:
	Player* mPlayer;
	Asteroid* mAsteroid;
	Coin* mCoin;

	sf::Texture mPlayerTexture;
	sf::Texture mAsteroidTexture;
	sf::Texture mCoinTexture;
};



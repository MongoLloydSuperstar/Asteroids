#include "Asteroid.h"

#include <iostream>

const EntityType TYPE = EnemyType;

const float SPEED = 5.0f;
const sf::Vector2f SCALE(1.0f, 1.0f);
const sf::Vector2f START_POS(400.0f, 300.0f);
const float Asteroid::SPAWN_COOLDOWN = 1.0f;
const int SCREEN_WIDTH = 768;

const std::string FILENAME = "AsteroidSprite.psd";

void Asteroid::Update()
{
	Movement();
}

#pragma region Con-/Destructors
Asteroid::Asteroid()
	: mType(TYPE)
{
	mTexture = new sf::Texture();
	if (!mTexture->loadFromFile(FILENAME))
	{
		std::cout << "Asteroid: Couldn't load texture!\n";
	}

	mSprite = new sf::Sprite(*mTexture);
	mSprite->setScale(SCALE);

}

Asteroid::Asteroid(const Asteroid& other)
	: mType(other.mType)
{
	mTexture = new sf::Texture();
	*mTexture = *other.mTexture;
	
	mSprite = new sf::Sprite;
	*mSprite = *other.mSprite;

	mSprite->setPosition(RandomStartPos());

}

Asteroid::~Asteroid()
{
	delete mSprite;
}
#pragma endregion

#pragma region Private Functions
void Asteroid::Movement()
{
	mSprite->move(0.0f, SPEED);
}

sf::Vector2f Asteroid::RandomStartPos()
{
	sf::Vector2f pos(static_cast <float> (rand()) / (static_cast <float> (RAND_MAX / SCREEN_WIDTH)), 1.0f);
	return pos;
}
#pragma endregion

#pragma region Getters/Setters
EntityType Asteroid::GetType() const
{
	return mType;
}

const sf::Vector2f& Asteroid::GetPosition() const
{
	return mSprite->getPosition();
}

sf::Sprite* Asteroid::GetSprite()
{
	return mSprite;
}
#pragma endregion
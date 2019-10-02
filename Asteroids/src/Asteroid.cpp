#include "Asteroid.h"

#include <iostream>

const EntityType TYPE = EnemyType;

const sf::Vector2f SPEED_RANGE(2.0f, 5.0f);
const sf::Vector2f SCALE(1.0f, 1.0f);
const sf::Vector2f START_POS(400.0f, 300.0f);
const sf::Vector2f Asteroid::SPAWN_COOLDOWN(0.5f, 2.0f);
const int SCREEN_WIDTH = 768;
const int SCREEN_HEIGHT = 1024;

const std::string Asteroid::FILENAME = "AsteroidSprite.psd";

void Asteroid::Update()
{
	Movement();
	KillConditions();
}

#pragma region Con-/Destructors
Asteroid::Asteroid(sf::Texture& texture)
	: mType(TYPE), mSpeed(0.0f)
{
	mRadius = texture.getSize().x / 2;
	
	mSprite = new sf::Sprite(texture);
	mSprite->setScale(SCALE);
}

Asteroid::Asteroid(const Asteroid& other)
	: mType(other.mType), mRadius(other.mRadius)
{	
	mSprite = new sf::Sprite();
	*mSprite = *other.mSprite;

	mSprite->setPosition(RandomStartPos());

	mSpeed = RandomizeRangef(SPEED_RANGE);
}

Asteroid::~Asteroid()
{
	delete mSprite;
}
#pragma endregion

#pragma region Private Functions
void Asteroid::Movement()
{
	mSprite->move(0.0f, mSpeed);
}

void Asteroid::KillConditions()
{
	const float xPos = mSprite->getPosition().x;
	const float yPos = mSprite->getPosition().y;
	
	const float xSize = mSprite->getLocalBounds().width;
	const float ySize = mSprite->getLocalBounds().height;
	
	const float xMax = SCREEN_WIDTH - xSize;
	const float yMax = SCREEN_HEIGHT - ySize;

	if (yPos > yMax)
	{
		mIsAlive = false;
	}
}

sf::Vector2f Asteroid::RandomStartPos()
{
	float range = SCREEN_WIDTH - mSprite->getLocalBounds().width;

	float xPos = RandomizeRangef(0.0f, range);
	float yPos = -mSprite->getLocalBounds().height;
	
	return sf::Vector2f(xPos, yPos);
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

float Asteroid::GetRadius() const
{
	return mRadius;
}
#pragma endregion

#include "Coin.h"

#include <iostream>

const EntityType TYPE = PickupType;

const sf::Vector2f SPEED_RANGE(2.0f, 5.0f);
const sf::Vector2f SCALE(1.0f, 1.0f);
const sf::Vector2f START_POS(400.0f, 300.0f);
const sf::Vector2f Coin::SPAWN_COOLDOWN(1.5f, 5.0f);
const int SCREEN_WIDTH = 768;
const int SCREEN_HEIGHT = 1024;

const std::string Coin::FILENAME = "CoinSprite.psd";

void Coin::Update()
{
	Movement();
	KillConditions();
}

#pragma region Con-/Destructors
Coin::Coin(sf::Texture& texture)
	: mType(TYPE)
{
	mRadius = texture.getSize().x / 2;
	
	mSprite = new sf::Sprite(texture);
	mSprite->setScale(SCALE);
}

Coin::Coin(const Coin& other)
	: mType(other.mType), mRadius(other.mRadius)
{
	mSprite = new sf::Sprite();
	*mSprite = *other.mSprite;

	mSprite->setPosition(RandomStartPos());
	
	mSpeed = RandomizeRangef(SPEED_RANGE);
}

Coin::~Coin()
{
	delete mSprite;
}
#pragma endregion

#pragma region Private Functions
void Coin::Movement()
{
	mSprite->move(0.0f, mSpeed);
}

void Coin::KillConditions()
{
	const float xPos = mSprite->getPosition().x;
	const float yPos = mSprite->getPosition().y;

	const float xSize = mSprite->getLocalBounds().width;
	const float ySize = mSprite->getLocalBounds().height;

	const float xMax = SCREEN_WIDTH - xSize;
	const float yMax = SCREEN_HEIGHT - ySize;

	if (yPos > yMax - 100)
	{
		mIsAlive = false;
	}
}

sf::Vector2f Coin::RandomStartPos()
{
	float range = SCREEN_WIDTH - mSprite->getLocalBounds().width;

	float xPos = RandomizeRangef(0.0f, range);
	float yPos = -mSprite->getLocalBounds().height;

	return sf::Vector2f(xPos, yPos);
}
#pragma endregion

#pragma region Getters/Setters

EntityType Coin::GetType() const
{
	return mType;
}

const sf::Vector2f& Coin::GetPosition() const
{
	return mSprite->getPosition();
}

sf::Sprite* Coin::GetSprite()
{
	return mSprite;
}

float Coin::GetRadius() const
{
	return mRadius;
}

#pragma endregion

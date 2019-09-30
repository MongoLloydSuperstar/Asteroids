#include "Coin.h"

#include <iostream>

const EntityType TYPE = PickupType;

const float SPEED = 5.0f;
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
	mSprite = new sf::Sprite(texture);
	mSprite->setScale(SCALE);
}

Coin::Coin(const Coin& other)
	: mType(other.mType)
{
	mSprite = new sf::Sprite();
	*mSprite = *other.mSprite;

	mSprite->setPosition(RandomStartPos());
}

Coin::~Coin()
{
	delete mSprite;
}
#pragma endregion

#pragma region Private Functions
void Coin::Movement()
{
	mSprite->move(0.0f, SPEED);
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
	float random = (float)rand() / (float)RAND_MAX;
	float range = SCREEN_WIDTH - mSprite->getLocalBounds().width;

	float xPos = random * range;
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

#pragma endregion
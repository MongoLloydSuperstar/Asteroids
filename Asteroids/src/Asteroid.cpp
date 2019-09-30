#include "Asteroid.h"

#include <iostream>

const EntityType TYPE = EnemyType;

const float SPEED = 5.0f;
const sf::Vector2f SCALE(1.0f, 1.0f);
const sf::Vector2f START_POS(400.0f, 300.0f);
const float Asteroid::SPAWN_COOLDOWN = 1.0f;
const int SCREEN_WIDTH = 768;
const int SCREEN_HEIGHT = 1024;

const std::string FILENAME = "AsteroidSprite.psd";

void Asteroid::Update()
{
	Movement();
	KillConditions();
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
	delete mTexture;
}
#pragma endregion

#pragma region Private Functions
void Asteroid::Movement()
{
	mSprite->move(0.0f, SPEED);
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
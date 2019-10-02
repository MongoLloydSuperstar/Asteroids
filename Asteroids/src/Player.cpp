#include "Player.h"

#include <iostream>

const EntityType TYPE = PlayerType;

const float SPEED = 5.0f;
const sf::Vector2f SCALE(1.0f, 1.0f);
const sf::Vector2f START_POS(400.0f, 300.0f);
const int SCREEN_WIDTH = 768;
const int SCREEN_HEIGHT = 1024;

const std::string Player::FILENAME("ShipSprite.psd");


void Player::Update()
{
	Movement();
}

#pragma region Con-/Destructors
Player::Player(const sf::Texture& texture)
	: mType(TYPE)
{
	mRadius = texture.getSize().x / 2;
	
	mSprite = new sf::Sprite(texture);
	mSprite->setPosition(START_POS);
	mSprite->setScale(SCALE);
}

Player::Player(const Player& other)
	: mType(other.mType), mRadius(other.mRadius)
{	
	mSprite = new sf::Sprite;
	*mSprite = *other.mSprite;
}

Player::~Player()
{
	delete mSprite;
}


#pragma endregion

#pragma region Private Functions
void Player::Movement()
{
	const float xPos = mSprite->getPosition().x;
	const float yPos = mSprite->getPosition().y;

	const float xSize = mSprite->getLocalBounds().width;
	const float ySize = mSprite->getLocalBounds().height;

	const float xMax = SCREEN_WIDTH - xSize;
	const float yMax = SCREEN_HEIGHT - ySize;

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left) && xPos > 0.0f)
	{
		mSprite->move(-SPEED, 0.0f);
	}	
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right) && xPos < xMax)
	{
		mSprite->move(SPEED, 0.0f);
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up) && yPos > 0.0f)
	{
		mSprite->move(0.0f, -SPEED);
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down) && yPos < yMax)
	{
		mSprite->move(0.0f, SPEED);
	}

	// Test boundary
	if (xPos < 0)
	{
		mSprite->setPosition(0.0f, yPos);
	}
	if (xPos > xMax)
	{
		mSprite->setPosition(xMax, yPos);
	}
	if (yPos < 0)
	{
		mSprite->setPosition(xPos, 0.0f);
	}
	if (yPos > yMax)
	{
		mSprite->setPosition(xPos, yMax);
	}
	
}
#pragma endregion

#pragma region Getters/Setters

EntityType Player::GetType() const
{
	return mType;
}

float Player::GetRadius() const
{
	return mRadius;
}

const sf::Vector2f& Player::GetPosition() const
{
	return mSprite->getPosition();
}

sf::Sprite* Player::GetSprite()
{
	return mSprite;
}
#pragma endregion

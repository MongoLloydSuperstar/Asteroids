#include "Player.h"

#include <iostream>

const EntityType TYPE = PlayerType;

const float SPEED = 5.0f;
const sf::Vector2f SCALE(1.0f, 1.0f);
const sf::Vector2f START_POS(400.0f, 300.0f);

const std::string FILENAME("ShipSprite.psd");


void Player::Update()
{
	Movement();
}

#pragma region Con-/Destructors
Player::Player()
	: mType(TYPE)
{
	mTexture = new sf::Texture();
	if (!mTexture->loadFromFile(FILENAME))
	{
		std::cout << "Player: Couldn't load texture!\n";
	}
		
	mSprite = new sf::Sprite(*mTexture);
	mSprite->setPosition(START_POS);
	mSprite->setScale(SCALE);
}

Player::Player(const Player& other)
	: mType(other.mType)
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
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
	{
		mSprite->move(-SPEED, 0.0f);
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
	{
		mSprite->move(SPEED, 0.0f);
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
	{
		mSprite->move(0.0f,-SPEED);
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
	{
		mSprite->move(0.0f, SPEED);
	}
}

#pragma endregion

#pragma region Getters/Setters

EntityType Player::GetType() const
{
	return mType;
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
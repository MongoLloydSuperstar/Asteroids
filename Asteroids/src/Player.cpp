#include "Player.h"

#include <iostream>

static const float PLAYER_SPEED = 5.0f;
static const sf::Vector2f PLAYER_SCALE = sf::Vector2f(0.5f, 0.5f);
static const sf::Vector2f PLAYER_START_POS = sf::Vector2f(0.5f, 0.5f);



Player::Player()
	: mType(EntityType::PlayerType)
{
	//mSprite.setTexture(sShipTexture);
	mSprite.setPosition(PLAYER_START_POS);
	mSprite.setScale(PLAYER_SCALE);
}

Player::~Player()
{
}

void Player::Init(const std::string& textureName)
{
	//sShipTexture.loadFromFile(textureName);
	//sShipTexture.setSmooth(true);	
}

void Player::Update()
{
	Movement();
}

#pragma region Private Functions

void Player::Movement()
{
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
	{
		mSprite.move(-PLAYER_SPEED, 0.0f);
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
	{
		mSprite.move(PLAYER_SPEED, 0.0f);
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
	{
		mSprite.move(0.0f,-PLAYER_SPEED);
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
	{
		mSprite.move(0.0f, PLAYER_SPEED);
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
	return mSprite.getPosition();
}

sf::Sprite Player::GetSprite()
{
	return mSprite;
}

#pragma endregion 
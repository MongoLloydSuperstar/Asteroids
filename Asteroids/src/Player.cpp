#include "Player.h"

#include <iostream>

static sf::Texture sShipTexture;

Player::Player(const sf::Vector2<int>& pos, const sf::Vector2<int>& size)
{
	mSprite.setTexture(sShipTexture);
}

Player::~Player()
{
}

void Player::Initialize(const std::string& textureName)
{
	sShipTexture.loadFromFile(textureName);
}

const sf::Vector2f& Player::getPosition() const
{
	return mSprite.getPosition();
}

sf::Sprite Player::GetSprite()
{
	return mSprite;
}

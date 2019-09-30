#pragma once

#include "Entity.h"

class Player : public Entity
{
public:
	void Update() override;

	Player() = delete;
	virtual ~Player();
	explicit Player(const sf::Texture& texture);
	explicit Player(const Player& other);


	EntityType GetType() const override;
	virtual const sf::Vector2f& GetPosition() const override;
	virtual sf::Sprite* GetSprite() override;

private:
	void Movement();
	
public:
	static const std::string FILENAME;

private:
	sf::Sprite* mSprite;
	sf::Texture mTexture;
	EntityType mType;

};

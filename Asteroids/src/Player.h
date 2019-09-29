#pragma once

#include "Entity.h"

class Player : public Entity
{
public:
	void Update() override;

	Player();
	explicit Player(const Player& other);
	virtual ~Player();

	EntityType GetType() const override;
	virtual const sf::Vector2f& GetPosition() const override;
	virtual sf::Sprite* GetSprite() override;

private:
	void Movement();

	sf::Sprite* mSprite;
	sf::Texture* mTexture;
	EntityType mType;

};

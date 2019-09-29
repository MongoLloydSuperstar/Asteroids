#pragma once

#include "Entity.h"

class Coin : public Entity
{
public:
	void Update() override;

	Coin();
	explicit Coin(const Coin& other);
	virtual ~Coin();
	
	EntityType GetType() const override;
	virtual const sf::Vector2f& GetPosition() const override;
	virtual sf::Sprite* GetSprite() override;
	
private:
	void Movement();
	sf::Vector2f RandomStartPos();

public:
	static const float SPAWN_COOLDOWN;
	
private:
	sf::Sprite* mSprite;
	sf::Texture* mTexture;
	EntityType mType;

};


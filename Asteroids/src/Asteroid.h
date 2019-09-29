#pragma once

#include "Entity.h"

class Asteroid : public Entity
{
public:
	void Update() override;

	Asteroid();
	explicit Asteroid(const Asteroid& other);
	virtual ~Asteroid();

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


#pragma once

#include "Entity.h"

class Asteroid : public Entity
{
public:
	void Update() override;

	Asteroid() = delete;
	explicit Asteroid(sf::Texture& texture);
	explicit Asteroid(const Asteroid& other);
	virtual ~Asteroid();

	EntityType GetType() const override;
	virtual const sf::Vector2f& GetPosition() const override;
	virtual sf::Sprite* GetSprite() override;

private:
	void Movement();
	void KillConditions();
	sf::Vector2f RandomStartPos();

public:
	static const float SPAWN_COOLDOWN;
	static const std::string FILENAME;
	
private:

	sf::Sprite* mSprite;
	sf::Texture mTexture;
	EntityType mType;

};


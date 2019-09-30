#pragma once

#include "Entity.h"

class Coin : public Entity
{
public:
	void Update() override;

	Coin() = delete;
	explicit Coin(sf::Texture& texture);
	explicit Coin(const Coin& other);
	virtual ~Coin();
	
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


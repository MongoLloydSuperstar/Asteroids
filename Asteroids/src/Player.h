#pragma once

#include "Entity.h"

class Player : public Entity
{
public:
	Player();
	virtual ~Player();

	static void Init(const std::string& textureName);
	 
	void Update() override;

	EntityType GetType() const override;
	virtual const sf::Vector2f& GetPosition() const override;
	virtual sf::Sprite GetSprite() override;

private:
	void Movement();
	
	sf::Sprite mSprite;
	EntityType mType;
};

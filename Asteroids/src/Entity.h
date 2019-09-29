#pragma once

#include <vector>
#include <SFML/System.hpp>
#include <SFML/Graphics.hpp>

enum EntityType
{
	NoType = 0, PlayerType, EnemyType, PickupType
};

class Entity
{
public:	
	virtual ~Entity() = default;

	virtual void Update() = 0;

	virtual EntityType GetType() const = 0;
	virtual const sf::Vector2f& GetPosition() const = 0;
	virtual sf::Sprite* GetSprite() = 0;
	
};

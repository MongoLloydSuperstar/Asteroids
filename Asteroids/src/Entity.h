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
	virtual float GetRadius() const = 0;
	virtual const sf::Vector2f& GetPosition() const = 0;
	virtual sf::Sprite* GetSprite() = 0;
	
	virtual bool IsAlive() { return mIsAlive; }
	virtual void Kill() { mIsAlive = false; }
	
	static float RandomizeRangef(float min, float max);
	static float RandomizeRangef(const sf::Vector2f& rangeVector);

protected:
	bool mIsAlive = true;
};

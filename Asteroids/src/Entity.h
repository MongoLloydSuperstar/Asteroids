#pragma once
#include <SFML/System.hpp>
#include <SFML/Graphics.hpp>

class Entity
{
public:
	virtual ~Entity() = default;

	virtual const sf::Vector2f& getPosition() const = 0;
	virtual sf::Sprite GetSprite() = 0;
};


#pragma once

#include "Entity.h"

class Player : public Entity
{
public:
	Player(const sf::Vector2<int>& pos, const sf::Vector2<int>& size);
	virtual ~Player();

	static void Initialize(const std::string& textureName);

	virtual const sf::Vector2f& getPosition() const override;
	virtual sf::Sprite GetSprite() override;
private:
	sf::Sprite mSprite;
};

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

	static Entity* Create(EntityType type);

	virtual EntityType GetType() const = 0;
	virtual const sf::Vector2f& GetPosition() const = 0;
	virtual sf::Sprite GetSprite() = 0;

protected:
	std::vector<sf::Texture> mTextures;	
};


//class Player : public Entity
//{
//public:
//	Player();
//	virtual ~Player();
//
//	static void Init(const std::string& textureName);
//
//	void Update() override;
//
//	EntityType GetType() const override;
//	virtual const sf::Vector2f& GetPosition() const override;
//	virtual sf::Sprite GetSprite() override;
//
//private:
//	void Movement();
//
//	sf::Sprite mSprite;
//	EntityType mType;
//};

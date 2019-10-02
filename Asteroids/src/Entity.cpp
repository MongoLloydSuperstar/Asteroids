#include "Entity.h"

float Entity::RandomizeRangef(const float min, const float max)
{
	float random = (float)rand() / (float)RAND_MAX;
	float range = max - min;

	return (random * range) + min;
}

float Entity::RandomizeRangef(const sf::Vector2f& rangeVector)
{
	float random = (float)rand() / (float)RAND_MAX;
	float range = rangeVector.y - rangeVector.x;

	return (random * range) + rangeVector.x;
}
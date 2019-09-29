#include "EntityManager.h"
#include <utility>
#include "Entity.h"

template<class T>
EntityManager<T>::EntityManager(const std::string& filename, std::function<T*(const sf::Texture&)> factory) :
	factory{std::move(factory)},
	texture{sf::Texture{}}
{
	if (!texture.loadFromFile(filename))
	{
		// TODO
	}
}

template<class T>
EntityManager<T>::~EntityManager()
{
	for (auto* entity : entities)
	{
		delete entity;
	}
	entities.clear();
}

template<class T>
T* EntityManager<T>::newEntity()
{
	const auto entity{ factory(texture) };
	entities.push_back(entity);
	return entity;
}

template<class T>
bool EntityManager<T>::removeEntity(const T* entity)
{
	typename std::vector<T*>::iterator removed {entities.end()};
	for (typename std::vector<T*>::iterator it {entities.begin()}; it != entities.end(); ++it)
	{
		if (*it == entity)
		{
			delete* it;
			entities.erase(it);
			return true;
		}
	}

	return false;
}

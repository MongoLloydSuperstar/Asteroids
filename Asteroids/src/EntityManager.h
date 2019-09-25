#include <functional>
#include <vector>
#include <SFML/Graphics/Texture.hpp>

class Entity;

template<class T>
class EntityManager
{
private:
	const std::function<T* (const sf::Texture&)> factory;
	sf::Texture texture;
	std::vector<T*> entities;

public:
	EntityManager(const std::string& filename, std::function<T*(const sf::Texture&)> factory);

	~EntityManager();

	T* newEntity();

	bool removeEntity(const T* entity);
};
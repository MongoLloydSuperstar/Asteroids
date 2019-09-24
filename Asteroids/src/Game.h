#pragma once

#include "Entity.h"
#include "Player.h"

#include <vector>

class Game
{
public:
	Game(sf::VideoMode videoMode, const std::string& title);
	~Game();

	void Run();
	
	void Update();
	void Render();

	void Init();

	sf::RenderWindow& GetRenderWindow();

private:
	typedef std::vector<Entity*> entities_t;
		
	entities_t mEntities;
	sf::RenderWindow mWindow;
};


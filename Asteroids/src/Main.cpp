#include <SFML/Graphics.hpp>
#include "Game.h"

int main()
{
	Game game(sf::VideoMode(768, 1024), "Asteroids");

	game.Init();
	game.Run();
	
	return 0;
}

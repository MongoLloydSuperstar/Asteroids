#include <SFML/Graphics.hpp>
#include "Player.h"

int main()
{
	sf::RenderWindow window(sf::VideoMode(200, 200), "Asteroids");

	Player::Initialize("ShipSprite.psd");
	Player* player = new Player(sf::Vector2<int>(40, 40), sf::Vector2<int>(460, 783));

	while (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();
		}

		
		window.clear(sf::Color::Black);
		window.draw(player->GetSprite());
		window.display();
	}

	return 0;
}

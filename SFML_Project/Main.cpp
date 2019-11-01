#include "SFML/include/SFML/Graphics.hpp"

int main()
{
	sf::RenderWindow window(sf::VideoMode(1080, 720), "Bouncing Mushroom");

	sf::Texture mushroomTexture;
	mushroomTexture.loadFromFile("Deps/Images/Mushroom.png");
	sf::Sprite mushroom(mushroomTexture);
	sf::Vector2u size = mushroomTexture.getSize();
	mushroom.setOrigin(size.x / 2, size.y / 2);
	sf::Vector2f increment(0.1f, 0.1f);

	while (window.isOpen())
	{
		//initiallize game objects

		//handle hardware input events
		sf::Event event;

		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
			{
				window.close();
			}
		}

		//update game objects
		/*If mushroom right side exceeds right side of screen or left side of mushroom exceeds the left side of the screen reverse x increment*/
		if ((mushroom.getPosition().x) + (size.x / 2) > window.getSize().x && (increment.x > 0) || (mushroom.getPosition().x) - (size.x / 2) < 0 && (increment.x < 0))
		{
			increment.x = -increment.x;
		}
		/*If mushroom top side exceeds top side of screen or bottom side of mushroom exceeds the bottom side of the screen reverse y increment*/
		if ((mushroom.getPosition().y) + (size.y / 2) > window.getSize().y && (increment.y > 0) || (mushroom.getPosition().y) - (size.y / 2) < 0 && (increment.y < 0))
		{
			increment.y = -increment.y;
		}

		mushroom.setPosition(mushroom.getPosition() + increment);
		window.clear(sf::Color::White);

		//render game objects
		window.draw(mushroom);

		window.display();
	}

	return 0;
}
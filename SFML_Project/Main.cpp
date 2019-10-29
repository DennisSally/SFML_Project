#include "SFML/include/SFML/Graphics.hpp"

sf::Vector2f windowSize(1024, 768);
sf::VideoMode videoMode(windowSize.x, windowSize.y);
sf::RenderWindow window(videoMode, "Country", sf::Style::Default);

int main()
{
	//Initiallize game objects
	sf::RectangleShape rect(sf::Vector2f(500.0f, 300.0f));
	rect.setFillColor(sf::Color::White);
	rect.setPosition(windowSize.x / 2, windowSize.y / 2);
	rect.setOrigin(sf::Vector2f(rect.getSize().x/2, rect.getSize().y/2));

	sf::CircleShape circle;
	circle.setRadius(60);
	circle.setFillColor(sf::Color::Red);
	circle.setPosition(windowSize.x / 2, windowSize.y / 2);
	circle.setOrigin(circle.getRadius(), circle.getRadius());

	sf::ConvexShape triangle;
	triangle.setPointCount(3);
	triangle.setPoint(0, sf::Vector2f(-300, 0));
	triangle.setPoint(1, sf::Vector2f(0, -350));
	triangle.setPoint(2, sf::Vector2f(300, 0));
	triangle.setFillColor(sf::Color::Cyan);
	triangle.setPosition(windowSize.x / 2, windowSize.y / 2);

	while (window.isOpen())
	{
		//handle hardware input events

		//update game objects
		window.clear(sf::Color::Black); //Clears screen and sets background colour.
		//render game objects
		window.draw(rect);
		window.draw(circle);
		window.draw(triangle);
		window.display(); //Displays the window
	}

	return 0;
}
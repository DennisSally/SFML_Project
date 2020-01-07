#ifndef WORLD

#include "Snake.h"

class World 
{
	public:
		World(sf::Vector2u lWindSize);
		~World();

		int GetBlockSize();
		void RespawnApple();

		void Update(Snake& lPlayer);
		void Render(sf::RenderWindow& lWindow);

	private:
		sf::Vector2u mWindowSize;
		sf::Vector2i mItem;
		int mBlockSize;
		sf::CircleShape mAppleShape;
		sf::RectangleShape mBounds[4];
};
#endif
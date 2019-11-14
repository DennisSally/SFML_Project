#ifndef GAME

#include "Window.h"

class cGame
{
	public:
		cGame();
		~cGame();

		void HandleInput();
		void Update();
		void Render();
		cWindow* GetWindow();
		sf::Time GetElapsed();
		void RestartClock();

	private:
		void MoveMushroom();
		cWindow mWindow;
		sf::Texture mMushroomTexture;
		sf::Sprite mMushroom;
		sf::Vector2u size = mMushroomTexture.getSize();
		sf::Vector2i mIncrement;
		sf::Clock mClock;
		sf::Time mElapsed;
};

#endif

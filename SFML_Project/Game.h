#ifndef GAME

#include "World.h"
#include "TextBox.h"

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
		cWindow mWindow;
		sf::Texture mMushroomTexture;
		sf::Sprite mMushroom;
		sf::Vector2u size = mMushroomTexture.getSize();
		sf::Vector2i mIncrement;
		sf::Clock mClock;
		float mElapsed;
		World mWorld;
		Snake mSnake;
		TextBox mTextBox;
};

#endif

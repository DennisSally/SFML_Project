#include "Game.h"

cGame::cGame() : mWindow("Snake", sf::Vector2u(800, 600)), 
mSnake(mWorld.GetBlockSize()), mWorld(sf::Vector2u(800, 600))
{
	mMushroomTexture.loadFromFile("Deps/Images/Mushroom.png");
	mMushroom.setTexture(mMushroomTexture);
	mIncrement = sf::Vector2i(64, 64);

	mTextBox.Setup(5, 14, 350, sf::Vector2f(225, 0));
	mTextBox.Add("Seeded random number generator with: " + std::to_string(time(NULL)));
}

cGame::~cGame()
{

}

void cGame::HandleInput()
{
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up) && mSnake.GetPhysicalDirection() != Direction::Down)	//If up is pressed and snake is not facing down.
	{
		mSnake.SetDirection(Direction::Up);
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down) && mSnake.GetPhysicalDirection() != Direction::Up)	//If down is pressed and snake is not facing up.
	{
		mSnake.SetDirection(Direction::Down);
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left) && mSnake.GetPhysicalDirection() != Direction::Right)	//If left is pressed and snake is not facing right.
	{
		mSnake.SetDirection(Direction::Left);
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right) && mSnake.GetPhysicalDirection() != Direction::Left)	//If right is pressed and snake is not facing left.
	{
		mSnake.SetDirection(Direction::Right);
	}
}

void cGame::Update()
{
	mWindow.UpdateMethod();

	float timestep = 1.0f / mSnake.GetSpeed();

	if (mElapsed >= timestep)
	{
		mSnake.Tick();
		mWorld.Update(mSnake);
		mElapsed -= timestep;
		if (mSnake.HasLost())
		{
			mSnake.Reset();
		}
	}
}

void cGame::Render()
{
	mWindow.BeginDraw(); //Clear the Window
	mWorld.Render(*mWindow.GetRenderWindow());
	mSnake.Render(*mWindow.GetRenderWindow());
	mTextBox.Render(*mWindow.GetRenderWindow());

	mWindow.EndDraw(); //Displays Texture
}

cWindow * cGame::GetWindow()
{
	return &mWindow;
}

sf::Time cGame::GetElapsed()
{
	return mClock.getElapsedTime();
}

void cGame::RestartClock()
{
	mElapsed += mClock.restart().asSeconds();
}
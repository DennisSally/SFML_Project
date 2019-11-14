#include "Game.h"

cGame::cGame() : mWindow("Bouncy Mushroom", sf::Vector2u(800, 700))
{
	mMushroomTexture.loadFromFile("Deps/Images/Mushroom.png");
	mMushroom.setTexture(mMushroomTexture);
	mIncrement = sf::Vector2i(64, 64);
}

cGame::~cGame()
{

}

void cGame::HandleInput()
{

}

void cGame::Update()
{
	mWindow.UpdateMethod();
	MoveMushroom();
}

void cGame::Render()
{
	mWindow.BeginDraw(); //Clear the Window
	mWindow.Draw(mMushroom); //Draw Mushroom
	mWindow.EndDraw(); //Displays Texture
}

cWindow * cGame::GetWindow()
{
	return &mWindow;
}

sf::Time cGame::GetElapsed()
{
	return sf::Time();
}

void cGame::RestartClock()
{
	mElapsed = mClock.restart();
}

void cGame::MoveMushroom()
{
	sf::Vector2u lWindowSize = mWindow.GetWindowSize();
	sf::Vector2u lTextureSize = mMushroomTexture.getSize();

	if ((mMushroom.getPosition().x > lWindowSize.x -lTextureSize.x) && (mIncrement.x > 0) || (mMushroom.getPosition().x < 0) && (mIncrement.x < 0))
	{
		mIncrement.x = -mIncrement.x;
	}
	if ((mMushroom.getPosition().y > lWindowSize.y - lTextureSize.y) && (mIncrement.y > 0) || (mMushroom.getPosition().y < 0) && (mIncrement.y < 0))
	{
		mIncrement.y = -mIncrement.y;
	}

	float fElapsed = mElapsed.asSeconds();
	mMushroom.setPosition(mMushroom.getPosition().x + mIncrement.x, mMushroom.getPosition().y + mIncrement.y);

}

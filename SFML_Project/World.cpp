#include "World.h"

World::World(sf::Vector2u lWindSize)
{
	mBlockSize = 16;

	mWindowSize = lWindSize;
	RespawnApple();
	mAppleShape.setFillColor(sf::Color::Red);	//Apple Colour
	mAppleShape.setRadius(mBlockSize / 2);	//Apple Size

	for (int i = 0; i < 4; ++i)
	{
		mBounds[i].setFillColor(sf::Color(150, 0, 0));	//Border colour.
		if (!((i + 1) % 2))
		{
			mBounds[i].setSize(sf::Vector2f(mWindowSize.x, mBlockSize));	//Define Horizontal Border.
		}
		else
		{
			mBounds[i].setSize(sf::Vector2f(mBlockSize, mWindowSize.y));	//Define Vertical Border.
		}
		if (i < 2)
		{
			mBounds[i].setPosition(0, 0);	//Starting position for our top and left side border.
		}
		else
		{
			mBounds[i].setOrigin(mBounds[i].getSize());
			mBounds[i].setPosition(sf::Vector2f(mWindowSize));	//Starting position for our bottom and right border.
		}
	}
}

World::~World()
{

}

int World::GetBlockSize()
{
	return mBlockSize;
}

void World::RespawnApple()
{
	//Get the spaces within the grid.
	int maxX = (mWindowSize.x / mBlockSize) - 2;
	int maxY = (mWindowSize.y / mBlockSize) - 2;

	mItem = sf::Vector2i(rand() % maxX + 1, rand() % maxY + 1);
	mAppleShape.setPosition(mItem.x * mBlockSize, mItem.y * mBlockSize);	//Set Random Position
}

void World::Update(Snake & lPlayer)
{
	if (lPlayer.GetPosition() == mItem)
	{
		lPlayer.Extend();	//Extend Snake.
		lPlayer.IncreaseScore();	//Increase Score.
		lPlayer.SetSpeed();	//Increase Speed.
		RespawnApple();
	}

	//Get Grid Sizes
	int gridSizeX = mWindowSize.x / mBlockSize;
	int gridSizeY = mWindowSize.y / mBlockSize;

	if ((lPlayer.GetPosition().x <= 0) || (lPlayer.GetPosition().y <= 0) || (lPlayer.GetPosition().x >= gridSizeX - 1) || (lPlayer.GetPosition().y >= gridSizeY - 1))	//If player exceeds boundaries.
	{
		lPlayer.Lose();	//Player Loses.
	}

}

void World::Render(sf::RenderWindow & lWindow)
{
	for (int i = 0; i < 4; ++i)
	{
		lWindow.draw(mBounds[i]);
	}
	lWindow.draw(mAppleShape);
}

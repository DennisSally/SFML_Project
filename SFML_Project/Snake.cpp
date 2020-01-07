#include "Snake.h"

Snake::Snake(int lBlockSize)
{
	mSize = lBlockSize;
	mBodyRect.setSize(sf::Vector2f(mSize - 1, mSize - 1));
	Reset();
}

Snake::~Snake()
{

}

void Snake::SetDirection(Direction lDir)
{
	mDir = lDir;
}

Direction Snake::GetDirection()
{
	return mDir;
}

Direction Snake::GetPhysicalDirection()
{
	if (mSnakeBody.size() <= 1)
	{
		return Direction::None;
	}

	SnakeSegment& head = mSnakeBody[0];
	SnakeSegment& neck = mSnakeBody[1];

	if (head.position.x == neck.position.x)
	{
		//If our head is lower than our neck pos then return down else we are going up return up.
		return (head.position.y > neck.position.y ? Direction::Down : Direction::Up);
	}
	else if (head.position.y == neck.position.y)
	{
		//If our head is right of our neck return right else we are going left return left.
		return(head.position.x > neck.position.x ? Direction::Right : Direction::Left);
	}

	return Direction::None;
}

int Snake::GetSpeed()
{
	return mSpeed;
}

void Snake::SetSpeed()
{
	mSpeed *= mMultiplySpeed;
}

sf::Vector2i Snake::GetPosition()
{
	//If our snake isnt empty get its front position else set it to 1,1.
	return (!mSnakeBody.empty() ? mSnakeBody.front().position : sf::Vector2i(1, 1));
}

int Snake::GetLives()
{
	return mLives;
}

int Snake::GetScore()
{
	return mScore;
}

void Snake::IncreaseScore()
{
	mScore += 10;
}

bool Snake::HasLost()
{
	return mLost;
}

void Snake::Lose()
{
	mLost = true;
}

void Snake::ToggleLost()
{
	mLost = !mLost;
}

void Snake::Extend()
{
	if (mSnakeBody.empty())	//If there is no snake return null.
	{
		return;
	}

	SnakeSegment& tailHead = mSnakeBody[mSnakeBody.size() - 1]; //Define our snake head.

	if (mSnakeBody.size() > 1)	//If there is a snake.
	{
		SnakeSegment& tailBone = mSnakeBody[mSnakeBody.size() - 2];	//Define snakes tail.

		if (tailHead.position.x == tailBone.position.x)	//If our snake is moving vertically.
		{
			if (tailHead.position.y > tailBone.position.y)	//If our snake is moving up.
			{
				mSnakeBody.push_back(SnakeSegment(tailHead.position.x, tailHead.position.y + 1));
			}
			else	//If our snake is moving down.
			{
				mSnakeBody.push_back(SnakeSegment(tailHead.position.x, tailHead.position.y - 1));
			}
		}
		else if (tailHead.position.y == tailBone.position.y)	//If our snake is move horizontally.
		{
			if (tailHead.position.x > tailBone.position.x)	//If our snake is moving right.
			{
				mSnakeBody.push_back(SnakeSegment(tailHead.position.x + 1, tailHead.position.y));
			}
			else	//If our snake is moving left.
			{
				mSnakeBody.push_back(SnakeSegment(tailHead.position.x - 1, tailHead.position.y));
			}
		}
		else
		{
			if (mDir == Direction::Up)
			{
				mSnakeBody.push_back(SnakeSegment(tailHead.position.x, tailHead.position.y + 1));
			}
			if (mDir == Direction::Down)
			{
				mSnakeBody.push_back(SnakeSegment(tailHead.position.x, tailHead.position.y - 1));
			}
			if (mDir == Direction::Left)
			{
				mSnakeBody.push_back(SnakeSegment(tailHead.position.x + 1, tailHead.position.y));
			}
			if (mDir == Direction::Right)
			{
				mSnakeBody.push_back(SnakeSegment(tailHead.position.x - 1, tailHead.position.y));
			}
		}
	}
}

void Snake::Reset()
{
	mSnakeBody.clear();	//Clear snake vector from previous.

	mSnakeBody.push_back(SnakeSegment(5, 7));	//Implement new snake.
	mSnakeBody.push_back(SnakeSegment(5, 6));
	mSnakeBody.push_back(SnakeSegment(5, 5));

	SetDirection(Direction::None); //Start off still.
	mSpeed = 5;	//Reset values.
	mLives = 3;
	mScore = 0;
	mLost = false;
}

void Snake::Move()
{
	for (int i = mSnakeBody.size() - 1; i > 0; --i)
	{
		mSnakeBody[i].position = mSnakeBody[i - 1].position;
	}

	if (mDir == Direction::Left)
	{
		--mSnakeBody[0].position.x;
	}
	if (mDir == Direction::Right)
	{
		++mSnakeBody[0].position.x;
	}
	if (mDir == Direction::Up)
	{
		--mSnakeBody[0].position.y;
	}
	if (mDir == Direction::Down)
	{
		++mSnakeBody[0].position.y;
	}
}

void Snake::Tick()	//UPDATE METHOD
{
	if (mSnakeBody.empty() || (mDir == Direction::None))	//Do We Have a Snake? Or a Direction?
	{
		return;
	}

	Move();
	CheckCollision();
}

void Snake::Cut(int lSegments)
{
	for (int i = 0; i < lSegments; ++i)
	{
		mSnakeBody.pop_back();	//Half our snake size.
	}

	--mLives;	//Remove a life.

	if (!mLives)	//If we have 0 Lives.
	{
		Lose();	//Player Loses.
		return;
	}
}

void Snake::Render(sf::RenderWindow & lWindow)
{
	if (mSnakeBody.empty())	//If we dont have a snake dont render.
	{
		return;
	}

	auto head = mSnakeBody.begin();	//Wheres our snake head? Define snake head.
	mBodyRect.setFillColor(sf::Color::Yellow);	//Our Snakes colour is yellow.
	mBodyRect.setPosition(head->position.x * mSize, head->position.y * mSize);	//
	lWindow.draw(mBodyRect);

	mBodyRect.setFillColor(sf::Color::Green);
	for (auto itr = mSnakeBody.begin() + 1; itr != mSnakeBody.end(); ++itr)
	{
		mBodyRect.setPosition(itr->position.x * mSize, itr->position.y * mSize);
		lWindow.draw(mBodyRect);
	}
}

void Snake::CheckCollision()
{
	if (mSnakeBody.size() < 5)	//If our snake consists of 4 sections/blocks it can never hit iself!
	{
		return;
	}

	SnakeSegment& head = mSnakeBody.front();	//Our snake head is equal to the front.
	for (auto itr = mSnakeBody.begin() + 1; itr != mSnakeBody.end(); ++itr)
	{
		if (itr->position == head.position)
		{
			int segments = mSnakeBody.end() - itr;
			Cut(segments);
			break;
		}
	}
}

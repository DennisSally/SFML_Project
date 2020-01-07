#ifndef SNAKE
#include "Window.h"

struct SnakeSegment
{
	SnakeSegment(int x, int y) : position(x, y) {}
	sf::Vector2i position;
};

using SnakeContainer = std::vector<SnakeSegment>;

enum class Direction
{
	None, Up, Down, Left, Right
};

class Snake
{
	public:
		Snake(int lBlockSize);
		~Snake();

		//Helper Methods.
		void SetDirection(Direction lDir);
		Direction GetDirection();
		Direction GetPhysicalDirection();

		int GetSpeed();
		void SetSpeed();
		sf::Vector2i GetPosition();
		int GetLives();
		int GetScore();
		void IncreaseScore();
		bool HasLost();

		void Lose();	//Handle losing here.
		void ToggleLost();

		void Extend();	//Grow the snake.
		void Reset();	//Reset to starting position.

		void Move();	//Movement Method.
		void Tick();	//Update Method.
		void Cut(int lSegments);	//Method for cutting snakes.
		void Render(sf::RenderWindow& lWindow);

	private:
		void CheckCollision();	//Checking for collisions.
		SnakeContainer mSnakeBody;	//Segment Vector.
		int mSize;	//Size of the graphics.
		Direction mDir;	//Current direction.
		int mMultiplySpeed = 1.2;	//Multiply Speed.
		int mSpeed;	//Speed of the snake.
		int mLives;	//Lives.
		int mScore;	//Score.
		bool mLost;	//Losing State.
		sf::RectangleShape mBodyRect;	//Shape used in rendering.
};
#endif
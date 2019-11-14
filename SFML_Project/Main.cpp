#include "Game.h"

int main()
{
	//Program Entry Point
	cGame game;	//Creating our game Object.
	
	while (!game.GetWindow()->IsDone())
	{
		// Game Loop
		game.HandleInput(); // Deals with Events/Input.
		game.Update();
		game.Render();
		sf::sleep(sf::seconds(1));
		game.RestartClock();
	}
	return 0;
}
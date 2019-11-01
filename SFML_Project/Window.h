#ifndef WINDOW
#include "SFML/include/SFML/Graphics.hpp"
#include "SFML/include/SFML/Window.hpp"

class cWindow
{
	public:
		cWindow();
		cWindow(const std::string& lWindowTitle, sf::Vector2u& lWindowSize);
		~cWindow();

		void BeginDraw(); //Clear Window
		void EndDraw(); // Display Window
		void Draw(sf::Drawable& lDrawable);
		void UpdateMethod();
		void ToggleFullScreen();
		bool IsDone();
		bool IsFullScreen();
		sf::Vector2u GetWindowSize();

	private:
		void SetUp(const std::string& lWindowTitle, const sf::Vector2u& lWindowSize);
		void Destroy();
		void Create();

		sf::RenderWindow mWindow;
		sf::Vector2u mWindowSize;
		std::string mWindowCaption;
		bool mIsDone;
		bool mIsFullScreen;
};

#endif

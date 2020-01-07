#include "Window.h"

cWindow::cWindow()
{
	SetUp("Window", sf::Vector2u(800, 600));
}

cWindow::cWindow(const std::string& lWindowTitle, const sf::Vector2u& lWindowSize)
{
	SetUp(lWindowTitle, lWindowSize);
}

cWindow::~cWindow()
{
	//This Destroys the window.
	Destroy();
}

void cWindow::BeginDraw()
{
	mWindow.clear(sf::Color::Black);
}

void cWindow::EndDraw()
{
	mWindow.display();
}

void cWindow::Draw(sf::Drawable & lDrawable)
{
	mWindow.draw(lDrawable);
}

void cWindow::UpdateMethod()
{
	sf::Event event;

	while (mWindow.pollEvent(event))
	{
		if (event.type == sf::Event::Closed)
		{
			mIsDone = true;
		}
		else if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::T)
		{
			ToggleFullScreen();
		}
	}
}

void cWindow::ToggleFullScreen()
{
	mIsFullScreen = !mIsFullScreen;
	Destroy();
	Create();
}

bool cWindow::IsDone()
{
	return mIsDone;
}

bool cWindow::IsFullScreen()
{
	return mIsFullScreen;
}

sf::RenderWindow * cWindow::GetRenderWindow()
{
	return &mWindow;
}

sf::Vector2u cWindow::GetWindowSize()
{
	return mWindowSize;
}

void cWindow::SetUp(const std::string& lWindowTitle, const sf::Vector2u& lWindowSize)
{
	mWindow.setFramerateLimit(60);
	mWindowCaption = lWindowTitle;
	mWindowSize = lWindowSize;
	mIsFullScreen = false;
	mIsDone = false;
	Create();
}

void cWindow::Destroy()
{
	mWindow.close();
}

void cWindow::Create()
{
	//This creates the window. (Ternarray)
	auto style = (mIsFullScreen ? sf::Style::Fullscreen : sf::Style::Default);
	mWindow.create({mWindowSize.x, mWindowSize.y, 32}, mWindowCaption, style);
}

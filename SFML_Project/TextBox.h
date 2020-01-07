#ifndef TEXTBOX

#include "SFML/include/SFML/Graphics.hpp"
#include "SFML/include/SFML/Window.hpp"

using MessageContainer = std::vector<std::string>;

class TextBox
{
	public:
		TextBox();
		TextBox(int lVisible, int lCharSize, int lWidth, sf::Vector2f lScreenPos);
		~TextBox();

		void Setup(int lVisible, int lCharSize, int lWidth, sf::Vector2f lScreenPos);
		void Add(std::string lMessage);
		void Clear();
		void Render(sf::RenderWindow& lWind);

	private:
		MessageContainer mMessages;
		int mNumVisible;

		sf::RectangleShape mBackDrop;
		sf::Font mFont;
		sf::Text mContent;
};

#endif

#pragma once
#include <string>
#include <SFML/Graphics.hpp>

namespace Draw
{
	using sf::Sprite;

	/*	Used for drawing 2D sprites. */
	class Draw2D
	{
	private:
		sf::RenderWindow window;
	public:
		Draw2D(const std::string & title, int width = 800, int height = 600);
		inline void clearScreen() { window.clear(); };
		inline void displayFrame() { window.display(); };
		inline void drawSprite(const Sprite & sprite) { window.draw(sprite); };
		void setVsync(bool b);
	};
}
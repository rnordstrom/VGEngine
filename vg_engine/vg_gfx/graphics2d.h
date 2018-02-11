#pragma once
#include <string>
#include <SFML/Graphics.hpp>

namespace Util
{
	/*	Utility class for grouping sprite clip values */
	class ClipRect
	{
	private:
		int x;
		int y;
		int w;
		int h;
	public:
		ClipRect(int xPos, int yPos, int width, int height);
		int xPos();
		int yPos();
		int width();
		int height();
	};
}

namespace Draw
{
	/*	Used for drawing 2D sprites. */
	class Draw2D
	{
	private:
		sf::RenderWindow window;
		void drawSprite(const sf::Sprite & sprite);
		void drawSprite(sf::Sprite & sprite, int xAbs, int yAbs);
	public:
		Draw2D(const std::string & title, int width = 800, int height = 600);
		void clearScreen();
		void displayFrame();
		void drawImage(const std::string & fileName);
		void drawImage(const std::string & fileName, int xAbs, int yAbs);
		void drawImage(const std::string & fileName, Util::ClipRect & clip, int xAbs = 0, int yAbs = 0);
	};
}
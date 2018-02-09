#pragma once
#include <string>
#include <SFML/Graphics.hpp>

/* Used for drawing 2D sprites. */
class Draw2D
{
private:
	sf::RenderWindow window;
	void drawImage(sf::Sprite sprite);
public:
	Draw2D(std::string title, int width = 800, int height = 600);
	void drawImage(std::string fileName);
	void drawImage(std::string fileName, int x, int y, int w, int h);
};
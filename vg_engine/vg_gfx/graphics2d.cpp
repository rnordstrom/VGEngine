#include "graphics2d.h"

Draw2D::Draw2D(std::string title, int width, int height)
{
	window.create(sf::VideoMode(width, height), title);
}

void Draw2D::drawImage(sf::Sprite sprite)
{
	window.clear();
	window.draw(sprite);
	window.display();
}

void Draw2D::drawImage(std::string fileName)
{
	sf::Texture texture;

	if (!texture.loadFromFile(fileName))
	{
		// TODO Handle error
	}

	sf::Sprite sprite;
	sprite.setTexture(texture);

	drawImage(sprite);
}

void Draw2D::drawImage(std::string fileName, int x, int y, int w, int h)
{
	sf::Texture texture;

	if (!texture.loadFromFile(fileName, sf::IntRect(x, y, w, h)))
	{
		// TODO Handle error
	}

	sf::Sprite sprite;
	sprite.setTexture(texture);

	drawImage(sprite);
}


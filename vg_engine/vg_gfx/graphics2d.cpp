#include "graphics2d.h"
using namespace Util;
using namespace Draw;

Util::ClipRect::ClipRect(int xPos, int yPos, int width, int height)
{
	x = xPos;
	y = yPos;
	w = width;
	h = height;
}

int ClipRect::xPos()
{
	return x;
}

int ClipRect::yPos()
{
	return y;
}

int ClipRect::width()
{
	return w;
}

int ClipRect::height()
{
	return h;
}

Draw2D::Draw2D(const std::string & title, int width, int height)
{
	window.create(sf::VideoMode(width, height), title);
}

/*	Draw sprite on screen. Use as a helper method to implement other
	drawing methods or within the framework by creating sprites from
	memory-loaded textures. */
void Draw2D::drawImage(const sf::Sprite & sprite)
{
	window.clear();
	window.draw(sprite);
	window.display();
}

/*	Load texture from file */
void Draw2D::drawImage(const std::string & fileName)
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

/*	Load texture from file and place at absolute position */
void Draw2D::drawImage(const std::string & fileName, int xAbs, int yAbs)
{
	sf::Texture texture;

	if (!texture.loadFromFile(fileName))
	{
		// TODO Handle error
	}

	sf::Sprite sprite;
	sprite.setTexture(texture);
	sprite.move(sf::Vector2f(xAbs, yAbs));

	drawImage(sprite);
}

/*	Load texture from file, clip a sprite and place at absolute position */
void Draw2D::drawImage(const std::string & fileName, ClipRect & clip, int xAbs, int yAbs)
{
	sf::Texture texture;

	if (!texture.loadFromFile(fileName, sf::IntRect(clip.xPos(), clip.yPos(), clip.width(), clip.height())))
	{
		// TODO Handle error
	}

	sf::Sprite sprite;
	sprite.setTexture(texture);
	sprite.move(sf::Vector2f(xAbs, yAbs));

	drawImage(sprite);
}


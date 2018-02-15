#include "graphics2d.h"
using namespace Util;
using namespace Draw;

/*	Construct an instance of ClipRect */
Util::ClipRect::ClipRect(int xPos, int yPos, int width, int height)
{
	x = xPos;
	y = yPos;
	w = width;
	h = height;
}

/*	Return the x-position of a ClipRect */
int ClipRect::xPos()
{
	return x;
}

/*	Return the y-position of a ClipRect */
int ClipRect::yPos()
{
	return y;
}

/*	Return the width of a ClipRect */
int ClipRect::width()
{
	return w;
}

/*	Return the height of a ClipRect */
int ClipRect::height()
{
	return h;
}

/*	Construct an instance of Draw2D; create and display a system window. */
Draw2D::Draw2D(const std::string & title, int width, int height)
{
	window.create(sf::VideoMode(width, height), title);
	window.setVerticalSyncEnabled(true);
}

/*	Draw sprite on screen. Use as a helper method to implement other
	drawing methods or within the framework by creating sprites from
	memory-loaded textures. */
void Draw2D::drawSprite(const sf::Sprite & sprite)
{
	window.draw(sprite);
}

void Draw2D::drawSprite(sf::Sprite & sprite, int xAbs, int yAbs)
{
	sprite.setPosition(sf::Vector2f(xAbs, yAbs));
	drawSprite(sprite);
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

	drawSprite(sprite);
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

	drawSprite(sprite, xAbs, yAbs);
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

	drawSprite(sprite, xAbs, yAbs);
}


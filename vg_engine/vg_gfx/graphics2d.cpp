#include "graphics2d.h"

using namespace Draw;

/*	Construct an instance of Draw2D; create and display a system window. */
Draw2D::Draw2D(const std::string & title, int width, int height)
{
	window.create(sf::VideoMode(width, height), title);
	window.setVerticalSyncEnabled(true);
}

/*	Toggle VSync on/off  */
void Draw2D::setVsync(bool b)
{
	window.setVerticalSyncEnabled(b);
}


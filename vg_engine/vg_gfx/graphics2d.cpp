#include "graphics2d.h"

using sf::RenderWindow;

using Render2D::Renderer;

/*	Construct an instance of Render2D; create and display a system window. */
Renderer::Renderer(const std::string & title, int width, int height)
{
	window.create(sf::VideoMode(width, height), title);
	window.setVerticalSyncEnabled(true);
}

/*	Toggle VSync on/off  */
void Renderer::setVsync(bool b)
{
	window.setVerticalSyncEnabled(b);
}


#include "graphics2d.h"

using sf::RenderWindow;

using Render2D::Renderer;

/*	Construct an instance of Render2D; create and display a system window_. */
Renderer::Renderer(const std::string & title, int width, int height)
{
	window_.create(sf::VideoMode(width, height), title);
	window_.setVerticalSyncEnabled(true);
}

/*	Toggle VSync on/off  */
void Renderer::setVsync(bool b)
{
	window_.setVerticalSyncEnabled(b);
}


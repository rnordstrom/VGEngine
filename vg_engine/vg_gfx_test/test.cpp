#include "pch.h"
#include <functional>
#include "../vg_gfx/graphics2d.h"

using sf::RenderWindow;
using sf::Texture;
using sf::Sprite;
using sf::IntRect;

using Render2D::Renderer;

class WindowTest : public ::testing::Test
{
protected:
	virtual void SetUp()
	{
		renderer = new Renderer("Test");
		renderer->setVsync(true);
	}

	Renderer * renderer;
};

TEST_F(WindowTest, TestDrawImages) 
{
	Texture texture;
	Sprite sprite;

	texture.loadFromFile("../Resources/test.png");
	sprite.setTexture(texture);

	while (renderer->windowIsOpen())
	{
		sf::Event event;
		while (renderer->pollWindowEvent(event))
		{
			if (event.type == sf::Event::Closed)
			{
				renderer->closeWindow();
			}
		}

		renderer->clearScreen();
		renderer->drawSprite(sprite);
		renderer->displayFrame();
	}
}
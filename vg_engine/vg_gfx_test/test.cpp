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

	while (renderer->getWindow().isOpen())
	{
		sf::Event event;
		while (renderer->getWindow().pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
			{
				renderer->getWindow().close();
			}
		}

		renderer->clearScreen();
		renderer->drawSprite(sprite);
		renderer->displayFrame();
	}
}
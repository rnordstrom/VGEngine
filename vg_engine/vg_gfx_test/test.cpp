#include "pch.h"
#include <functional>
#include "../vg_gfx/graphics2d.h"

using sf::Texture;
using sf::Sprite;
using sf::IntRect;

class WindowTest : public ::testing::Test
{
protected:
	virtual void SetUp()
	{
		draw2d = new Draw::Draw2D("Test");
		draw2d->setVsync(true);
	}

	Draw::Draw2D * draw2d;
};

TEST_F(WindowTest, TestDrawImages) 
{
	int runs = 1000;
	Texture texture;
	Sprite sprite;

	texture.loadFromFile("../Resources/test.png");
	sprite.setTexture(texture);

	while (runs--)
	{
		draw2d->clearScreen();
		draw2d->drawSprite(sprite);
		draw2d->displayFrame();
	}
}
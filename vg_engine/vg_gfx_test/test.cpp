#include "pch.h"
#include <functional>
#include "../vg_gfx/graphics2d.h"

class WindowTest : public ::testing::Test
{
protected:
	virtual void SetUp()
	{
		draw2d = new Draw::Draw2D("Test");
	}

	Draw::Draw2D * draw2d;
};

TEST_F(WindowTest, TestDrawImages) 
{
	Util::ClipRect clipRect(0, 0, 32, 32);
	int runs = 1000;

	while (runs--)
	{
		draw2d->clearScreen();

		draw2d->drawImage("../Resources/test.png");
		draw2d->drawImage("../Resources/test.png", 64, 64);
		draw2d->drawImage("../Resources/test.png", clipRect, 128, 128);

		draw2d->displayFrame();
	}
}
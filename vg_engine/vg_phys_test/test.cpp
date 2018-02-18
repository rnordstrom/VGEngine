#include "pch.h"
#include <string>
#include <memory>
#include "../vg_phys/pysics2d.h"
#include "../vg_data/actors2d.h"
#include "../vg_data/geometry2d.h"
#include "../vg_anim/animate2d.h"

using std::string;
using std::shared_ptr;
using std::make_shared;

using sf::Texture;
using sf::Sprite;

using Physics2D::CollisionDetector;
using Physics2D::Motor;

using Actor2D::Entity;
using Actor2D::EntityWrapper;

using Geometry::Coordinates;
using Geometry::Dimensions;

using Animate2D::Animator;

class MotionTest : public ::testing::Test
{
protected:
	MotionTest() {};
	virtual void SetUp()
	{
		CollisionDetector detector(SCREEN_WIDTH, SCREEN_HEIGHT);
		motor = new Motor(detector);

		animator = new Animator("Test");

		Entity entity;

		shared_ptr<Texture> texturePtr = make_shared<Texture>();
		texturePtr->loadFromFile(TEXTURE_FILE_NAME);

		Sprite sprite;
		sprite.setTexture(*texturePtr);

		wrapper = new EntityWrapper<Texture, Sprite>(entity, texturePtr, sprite);
	}

	const int SCREEN_WIDTH = 800;
	const int SCREEN_HEIGHT = 600;
	const string & TEXTURE_FILE_NAME = "../Resources/test.png";
	Motor * motor;
	EntityWrapper<Texture, Sprite> * wrapper;
	Animator * animator;
};

TEST_F(MotionTest, TestMotionRight) 
{
	Coordinates coordinates{ 400.0, 0.0 };
	Dimensions dimensions{ 64, 64 };

	Entity entity(coordinates, dimensions, 0, TEXTURE_FILE_NAME);

	wrapper->entity() = entity;

	while (animator->getRenderer().getWindow().isOpen())
	{
		sf::Event event;
		while (animator->getRenderer().getWindow().pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
			{
				animator->getRenderer().getWindow().close();
			}
		}

		animator->getRenderer().clearScreen();
		motor->moveRight(wrapper->entity());
		animator->apply(*wrapper);
		animator->getRenderer().displayFrame();
	}
}

TEST_F(MotionTest, TestMotionLeft)
{
	Coordinates coordinates{ 400.0, 0.0 };
	Dimensions dimensions{ 64, 64 };

	Entity entity(coordinates, dimensions, 0, TEXTURE_FILE_NAME);

	wrapper->entity() = entity;

	while (animator->getRenderer().getWindow().isOpen())
	{
		sf::Event event;
		while (animator->getRenderer().getWindow().pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
			{
				animator->getRenderer().getWindow().close();
			}
		}

		animator->getRenderer().clearScreen();
		motor->moveLeft(wrapper->entity());
		animator->apply(*wrapper);
		animator->getRenderer().displayFrame();
	}
}

TEST_F(MotionTest, TestMotionUp)
{
	Coordinates coordinates{ 0.0, 300.0 };
	Dimensions dimensions{ 64, 64 };

	Entity entity(coordinates, dimensions, 0, TEXTURE_FILE_NAME);

	wrapper->entity() = entity;

	while (animator->getRenderer().getWindow().isOpen())
	{
		sf::Event event;
		while (animator->getRenderer().getWindow().pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
			{
				animator->getRenderer().getWindow().close();
			}
		}

		animator->getRenderer().clearScreen();
		motor->moveUp(wrapper->entity());
		animator->apply(*wrapper);
		animator->getRenderer().displayFrame();
	}
}

TEST_F(MotionTest, TestMotionDown)
{
	Coordinates coordinates{ 0.0, 300.0 };
	Dimensions dimensions{ 64, 64 };

	Entity entity(coordinates, dimensions, 0, TEXTURE_FILE_NAME);

	wrapper->entity() = entity;

	while (animator->getRenderer().getWindow().isOpen())
	{
		sf::Event event;
		while (animator->getRenderer().getWindow().pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
			{
				animator->getRenderer().getWindow().close();
			}
		}

		animator->getRenderer().clearScreen();
		motor->moveDown(wrapper->entity());
		animator->apply(*wrapper);
		animator->getRenderer().displayFrame();
	}
}

TEST_F(MotionTest, TestMotionDiagonalDownRight)
{
	Coordinates coordinates{ 400.0, 300.0 };
	Dimensions dimensions{ 64, 64 };

	Entity entity(coordinates, dimensions, 0, TEXTURE_FILE_NAME);

	wrapper->entity() = entity;

	while (animator->getRenderer().getWindow().isOpen())
	{
		sf::Event event;
		while (animator->getRenderer().getWindow().pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
			{
				animator->getRenderer().getWindow().close();
			}
		}

		animator->getRenderer().clearScreen();
		motor->moveDown(wrapper->entity());
		motor->moveRight(wrapper->entity());
		animator->apply(*wrapper);
		animator->getRenderer().displayFrame();
	}
}

TEST_F(MotionTest, TestMotionDiagonalUpRight)
{
	Coordinates coordinates{ 400.0, 300.0 };
	Dimensions dimensions{ 64, 64 };

	Entity entity(coordinates, dimensions, 0, TEXTURE_FILE_NAME);

	wrapper->entity() = entity;

	while (animator->getRenderer().getWindow().isOpen())
	{
		sf::Event event;
		while (animator->getRenderer().getWindow().pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
			{
				animator->getRenderer().getWindow().close();
			}
		}

		animator->getRenderer().clearScreen();
		motor->moveUp(wrapper->entity());
		motor->moveRight(wrapper->entity());
		animator->apply(*wrapper);
		animator->getRenderer().displayFrame();
	}
}

TEST_F(MotionTest, TestMotionDiagonalDownLeft)
{
	Coordinates coordinates{ 400.0, 300.0 };
	Dimensions dimensions{ 64, 64 };

	Entity entity(coordinates, dimensions, 0, TEXTURE_FILE_NAME);

	wrapper->entity() = entity;

	while (animator->getRenderer().getWindow().isOpen())
	{
		sf::Event event;
		while (animator->getRenderer().getWindow().pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
			{
				animator->getRenderer().getWindow().close();
			}
		}

		animator->getRenderer().clearScreen();
		motor->moveDown(wrapper->entity());
		motor->moveLeft(wrapper->entity());
		animator->apply(*wrapper);
		animator->getRenderer().displayFrame();
	}
}

TEST_F(MotionTest, TestMotionDiagonalUpLeft)
{
	Coordinates coordinates{ 400.0, 300.0 };
	Dimensions dimensions{ 64, 64 };

	Entity entity(coordinates, dimensions, 0, TEXTURE_FILE_NAME);

	wrapper->entity() = entity;

	while (animator->getRenderer().getWindow().isOpen())
	{
		sf::Event event;
		while (animator->getRenderer().getWindow().pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
			{
				animator->getRenderer().getWindow().close();
			}
		}

		animator->getRenderer().clearScreen();
		motor->moveUp(wrapper->entity());
		motor->moveLeft(wrapper->entity());
		animator->apply(*wrapper);
		animator->getRenderer().displayFrame();
	}
}
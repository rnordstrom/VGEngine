#include "pch.h"
#include <string>
#include <memory>
#include "../vg_anim/animate2d.h"
#include "../vg_data/actors2d.h"
#include "../vg_data/geometry2d.h"

using std::string;
using std::shared_ptr;

using sf::Texture;
using sf::Sprite;

using Animate2D::Animator;

using Actor2D::Entity;
using Actor2D::EntityWrapper;

using Geometry::Coordinates;
using Geometry::Dimensions;

TEST(AnimationTests, TestApply) 
{
	Animator animator("Test");

	Coordinates coordinates{ 0.0, 0.0 };
	Dimensions dimensions{ 64, 64 };
	float angleOfRotation = 0.0;
	string textureFileName = "../Resources/test.png";

	Entity entity(coordinates, dimensions, angleOfRotation, textureFileName);

	shared_ptr<Texture> texturePtr = std::make_shared<Texture>();
	texturePtr->loadFromFile(textureFileName);

	Sprite sprite;
	sprite.setTexture(*texturePtr);

	EntityWrapper<Texture, Sprite> wrapper(entity, texturePtr, sprite);

	while (animator.getRenderer().getWindow().isOpen())
	{
		sf::Event event;
		while (animator.getRenderer().getWindow().pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
			{
				animator.getRenderer().getWindow().close();
			}
		}

		// Test various manipulations of the Entity
		wrapper.entity().coordinates().x += 1.5;
		wrapper.entity().coordinates().y += 1;
		wrapper.entity().setAngleOfRotation(wrapper.entity().getAngleOfRotation() + 2);

		animator.getRenderer().clearScreen();
		animator.apply(wrapper);
		animator.getRenderer().displayFrame();
	}
}
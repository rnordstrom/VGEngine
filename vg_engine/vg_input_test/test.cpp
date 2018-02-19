#include "pch.h"
#include <string>
#include <memory>
#include "../vg_data/actors2d.h"
#include "../vg_data/geometry2d.h"
#include "../vg_input/input2d.h"

using std::string;
using std::shared_ptr;
using std::make_shared;

using sf::Texture;
using sf::Sprite;

using Actor2D::Entity;
using Actor2D::EntityWrapper;

using Geometry::Coordinates;
using Geometry::Dimensions;

using Input2D::InputHandler;

TEST(InputTests, TestInput) 
{
	Coordinates coordinates{ 0.0, 0.0 };
	Dimensions dimensions{ 64, 64 };
	string textureFileName = "../Resources/test.png";

	Entity entity(coordinates, dimensions, 0, textureFileName);

	shared_ptr<Texture> texturePtr = make_shared<Texture>();
	texturePtr->loadFromFile(textureFileName);

	Sprite sprite;
	sprite.setTexture(*texturePtr);

	EntityWrapper<Texture, Sprite> wrapper(entity, texturePtr, sprite);

	InputHandler handler("Test", 800, 600);
	handler.startInputLoop(wrapper);
}
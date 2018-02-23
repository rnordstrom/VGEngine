#include "pch.h"
#include "../vg_data/actors2d.h"
#include "../vg_data/geometry2d.h"
#include "../vg_input/input2d.h"
#include "../vg_core/entities.h"

using Actor2D::Entity;
using Actor2D::EntityWrapper;

using Geometry::Coordinates;
using Geometry::Dimensions;

using Input2D::InputHandler;

using Registry::EntityRegistry;
using Registry::Role;

using sf::Texture;
using sf::Sprite;

using std::string;

TEST(InputTests, TestInput) 
{
	Coordinates coordinates{ 0.0, 0.0 };
	Dimensions dimensions{ 64, 64 };
	string textureFileName = "../Resources/test.png";

	Entity entity(coordinates, dimensions, 0, textureFileName);

	EntityRegistry::getInstance().registerEntity(entity, Role::player);

	InputHandler handler("Test", 800, 600);
	handler.startInputLoop();
}
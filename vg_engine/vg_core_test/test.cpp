#include "pch.h"
#include "../vg_core/entities.h"
#include "../vg_data/actors2d.h"
#include "../vg_data/geometry2d.h"

using Registry::EntityRegistry;
using Registry::Role;

using Actor2D::Entity;
using Actor2D::EntityWrapper;

using Geometry::Coordinates;
using Geometry::Dimensions;

using sf::Texture;
using sf::Sprite;

using std::vector;
using std::string;

TEST(RegistryTests, TestEntityRegistry) 
{
	Coordinates coordinates{ 0.0, 0.0 };
	Dimensions dimensions{ 64, 64 };
	const string TEXTURE_FILE_NAME = "../Resources/test.png";

	Entity entity(coordinates, dimensions, 0.0, TEXTURE_FILE_NAME);

	EntityRegistry::getInstance().registerEntity(entity, Role::player);

	auto wrappers = EntityRegistry::getInstance().getByRole(Role::player);

	ASSERT_EQ(1, wrappers.size());
	EXPECT_EQ(entity, wrappers.at(0).entity());

	Entity altEntity(coordinates, dimensions, 3.0, TEXTURE_FILE_NAME); // Different angle of rotation

	EntityRegistry::getInstance().registerEntity(altEntity, Role::player);

	wrappers = EntityRegistry::getInstance().getByRole(Role::player);

	ASSERT_EQ(1, wrappers.size());
	EXPECT_EQ(altEntity, wrappers.at(0).entity());
}
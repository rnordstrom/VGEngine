#include "pch.h"
#include <memory>
#include "../vg_data/actors2d.h"
#include "../vg_data/geometry2d.h"

using Actor2D::Entity;
using Actor2D::EntityWrapper;

using Geometry::Coordinates;
using Geometry::Dimensions;

using std::string;
using std::shared_ptr;

TEST(EntityTest, TestConstructor) 
{
	Coordinates coordinates{5, 15};
	Dimensions dimensions{10, 25};
	string textureFileName = "test.png";

	Entity entity(coordinates, dimensions, textureFileName);

	EXPECT_EQ(coordinates.x, entity.getCoordinates().x);
	EXPECT_EQ(coordinates.y, entity.getCoordinates().y);

	EXPECT_EQ(dimensions.width, entity.getDimensions().width);
	EXPECT_EQ(dimensions.height, entity.getDimensions().height);

	EXPECT_STREQ(textureFileName.c_str(), entity.getTextureFileName().c_str());
}

TEST(EntityTest, TestSetMethods)
{
	Entity emptyEntity;

	Coordinates coordinates{ 15, 50 };
	Dimensions dimensions{ 20, 25 };

	emptyEntity.setCoordinates(coordinates);

	EXPECT_EQ(coordinates.x, emptyEntity.getCoordinates().x);
	EXPECT_EQ(coordinates.y, emptyEntity.getCoordinates().y);

	emptyEntity.setDimensions(dimensions);

	EXPECT_EQ(dimensions.width, emptyEntity.getDimensions().width);
	EXPECT_EQ(dimensions.height, emptyEntity.getDimensions().height);
}

TEST(EntityWrapperTest, TestConstructor)
{
	Entity emptyEntity;
	shared_ptr<string> texture = std::make_shared<string>("Dummy texture representation");
	string sprite = "Dummy sprite representation";
	string spriteCopy(sprite);

	EntityWrapper<string, string> wrapper1(emptyEntity, texture, sprite);
	EntityWrapper<string, string> wrapper2(emptyEntity, texture, spriteCopy);

	ASSERT_EQ(wrapper1.getEntity(), wrapper2.getEntity());
	EXPECT_EQ(wrapper1.getTexture(), wrapper2.getTexture());
	EXPECT_STREQ(wrapper1.getTexture()->c_str(), wrapper2.getTexture()->c_str());
	EXPECT_STREQ(wrapper1.getSprite().c_str(), wrapper2.getSprite().c_str());
}
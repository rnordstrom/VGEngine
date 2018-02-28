#include "pch.h"
#include <memory>
#include "../vg_data/actors2d.h"
#include "../vg_data/geometry2d.h"

using Actor2D::Entity;
using Actor2D::EntityWrapper;
using Actor2D::NPC;
using Actor2D::GoalType;

using Geometry::Coordinates;
using Geometry::Dimensions;

using std::string;
using std::shared_ptr;

TEST(EntityTests, TestConstructor) 
{
	Coordinates coordinates{5, 15};
	Dimensions dimensions{10, 25};
	float angleOfRotation = 0.0;
	string textureFileName = "test.png";

	Entity entity(coordinates, dimensions, angleOfRotation, textureFileName);

	EXPECT_EQ(coordinates.x, entity.coordinates().x);
	EXPECT_EQ(coordinates.y, entity.coordinates().y);

	EXPECT_EQ(dimensions.width, entity.dimensions().width);
	EXPECT_EQ(dimensions.height, entity.dimensions().height);

	EXPECT_EQ(angleOfRotation, entity.getAngleOfRotation());

	EXPECT_STREQ(textureFileName.c_str(), entity.getTextureFileName().c_str());
}

TEST(EntityTests, TestGetSet)
{
	Entity emptyEntity;

	Coordinates coordinates{ 15, 50 };
	Dimensions dimensions{ 20, 25 };
	float angleOfRotation = 0.0;

	emptyEntity.coordinates() = coordinates;

	EXPECT_EQ(coordinates.x, emptyEntity.coordinates().x);
	EXPECT_EQ(coordinates.y, emptyEntity.coordinates().y);

	emptyEntity.dimensions() = dimensions;

	EXPECT_EQ(dimensions.width, emptyEntity.dimensions().width);
	EXPECT_EQ(dimensions.height, emptyEntity.dimensions().height);

	emptyEntity.setAngleOfRotation(angleOfRotation);

	EXPECT_EQ(angleOfRotation, emptyEntity.getAngleOfRotation());
}

TEST(EntityWrapperTests, TestConstructor)
{
	Entity emptyEntity;
	shared_ptr<string> texture = std::make_shared<string>("Dummy texture representation");
	string sprite = "Dummy sprite representation";
	string spriteCopy(sprite);

	EntityWrapper<string, string> wrapper1(emptyEntity, texture, sprite);
	EntityWrapper<string, string> wrapper2(emptyEntity, texture, spriteCopy);

	ASSERT_EQ(wrapper1.entity(), wrapper2.entity());
	EXPECT_EQ(wrapper1.getTexture(), wrapper2.getTexture());
	EXPECT_STREQ(wrapper1.getTexture()->c_str(), wrapper2.getTexture()->c_str());
	EXPECT_STREQ(wrapper1.sprite().c_str(), wrapper2.sprite().c_str());
}

TEST(NpcTests, TestGetGoalByPriority)
{
	NPC npc;

	auto firstPriorityGoal = npc.getGoalByPriority(1);
	auto secondPriorityGoal = npc.getGoalByPriority(2);

	ASSERT_EQ(GoalType::interaction, firstPriorityGoal.first);
	ASSERT_EQ(GoalType::location, secondPriorityGoal.first);
}

TEST(NpcTests, TestSetGoalPriority)
{
	NPC npc;

	npc.setGoalPriority(GoalType::location, 1);

	auto firstPriorityGoal = npc.getGoalByPriority(1);
	auto secondPriorityGoal = npc.getGoalByPriority(2);

	ASSERT_EQ(GoalType::location, firstPriorityGoal.first);
	ASSERT_EQ(GoalType::interaction, secondPriorityGoal.first);
}

TEST(NpcTests, TestGetGoalByType) 
{
	NPC npc;

	auto interactionGoal = npc.getGoalByType(GoalType::interaction);

	ASSERT_EQ(GoalType::interaction, interactionGoal.first);
}

TEST(NpcTests, TestSetGoalByType)
{
	NPC npc;
	Coordinates walkHere{ 64, 64 };

	npc.setGoalByType(GoalType::location, walkHere);

	auto locationGoal = npc.getGoalByType(GoalType::location);

	ASSERT_EQ(walkHere.x, locationGoal.second.x);
	ASSERT_EQ(walkHere.y, locationGoal.second.y);
}
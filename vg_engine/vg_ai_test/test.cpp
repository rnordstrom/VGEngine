#include "pch.h"

#include "../vg_ai/ai.h"
#include "../vg_data/actors2d.h"
#include "../vg_data/geometry2d.h"

using AI::InteractionHandler;

using Actor2D::NPC;
using Actor2D::Entity;

using Geometry::Coordinates;
using Geometry::Dimensions;

TEST(InteractionTests, TestCanDetect)
{
	InteractionHandler interactionHandler;

	Coordinates entityCoordinates{ 0, 0 };
	Coordinates npcCoordinates{ 400, 300 };
	Dimensions dimensions{ 64, 64 };

	Entity entity(entityCoordinates, dimensions, 0.0, " ");
	NPC npc(npcCoordinates, dimensions, 0.0, " ");

	entity.coordinates().x = 241;
	entity.coordinates().y = 300;

	ASSERT_TRUE(interactionHandler.canDetect(npc, entity));

	entity.coordinates().x = 559;
	entity.coordinates().y = 300;

	ASSERT_TRUE(interactionHandler.canDetect(npc, entity));

	entity.coordinates().x = 400;
	entity.coordinates().y = 141;

	ASSERT_TRUE(interactionHandler.canDetect(npc, entity));

	entity.coordinates().x = 400;
	entity.coordinates().y = 459;

	ASSERT_TRUE(interactionHandler.canDetect(npc, entity));
}

TEST(InteractionTests, TestCanInteract)
{
	InteractionHandler interactionHandler;

	Coordinates entityCoordinates{ 0, 0 };
	Coordinates npcCoordinates{ 400, 300 };
	Dimensions dimensions{ 64, 64 };

	Entity entity(entityCoordinates, dimensions, 0.0, " ");
	NPC npc(npcCoordinates, dimensions, 0.0, " ");

	entity.coordinates().x = 369;
	entity.coordinates().y = 300;

	ASSERT_TRUE(interactionHandler.canInteract(npc, entity));

	entity.coordinates().x = 495;
	entity.coordinates().y = 300;

	ASSERT_TRUE(interactionHandler.canInteract(npc, entity));

	entity.coordinates().x = 400;
	entity.coordinates().y = 205;

	ASSERT_TRUE(interactionHandler.canInteract(npc, entity));

	entity.coordinates().x = 400;
	entity.coordinates().y = 395;

	ASSERT_TRUE(interactionHandler.canInteract(npc, entity));
}
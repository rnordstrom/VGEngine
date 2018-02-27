#include "ai.h"

using AI::PathFinder;
using AI::InteractionHandler;
using AI::Coordinator;

using Actor2D::NPC;
using Actor2D::Entity;
using Actor2D::GoalType;

using Geometry::Coordinates;
using Geometry::Dimensions;

using std::vector;

bool PathFinder::findPath(NPC & npc, const Coordinates & goal)
{
	/*	TODO: Implement some variant of A*. It's unlikely that an effective
		implementation can be found without concurrent processing, so it's
		probably best to shift focus to vg_thread (or otherwise, a section of
		the core module) for now. */

	return false;
}

bool InteractionHandler::insideRange(NPC & npc, Dimensions range, Entity & entity)
{
	Coordinates rangeCoords;

	rangeCoords.x = (npc.coordinates().x - range.width / 2) + npc.dimensions().width / 2;
	rangeCoords.y = (npc.coordinates().y - range.height / 2) + npc.dimensions().height / 2;

	const float ENTITY_LEFT = entity.coordinates().x;
	const float ENTITY_TOP = entity.coordinates().y;
	const float ENTITY_RIGHT = entity.coordinates().x + entity.dimensions().width;
	const float ENTITY_BOTTOM = entity.coordinates().y + entity.dimensions().height;

	const float RANGE_LEFT = rangeCoords.x;
	const float RANGE_TOP = rangeCoords.y;
	const float RANGE_RIGHT = rangeCoords.x + range.width;
	const float RANGE_BOTTOM = rangeCoords.y + range.height;

	if (ENTITY_LEFT < RANGE_RIGHT && ENTITY_RIGHT > RANGE_LEFT && ENTITY_TOP < RANGE_BOTTOM && ENTITY_BOTTOM > RANGE_TOP)
	{
		return true;
	}

	return false;
}

bool InteractionHandler::canDetect(NPC & npc, Entity & entity)
{
	return insideRange(npc, npc.detectionRange(), entity);
}

bool InteractionHandler::canInteract(NPC & npc, Entity & entity)
{
	return insideRange(npc, npc.interactionRange(), entity);
}

void InteractionHandler::handleInteraction(NPC & npc, Entity entity)
{
	// TODO: Decide what constitutes an interaction
}

void Coordinator::resolveGoals(NPC & npc, vector<Entity> entities)
{
	for (int p = 1; p < npc.numGoals(); p++)
	{
		auto goal = npc.getGoalByPriority(p);

		if (goal.first == GoalType::location)
		{
			pathFinder_.findPath(npc, goal.second);
		}
		else if (goal.first == GoalType::interaction)
		{
			for (Entity entity : entities)
			{
				if (interactionHandler_.canDetect(npc, entity))
				{
					// TODO: Make it possible to ignore entities within range and target a pre-determined goal
					npc.setGoalByType(GoalType::interaction, entity.coordinates());
					// TODO: In the case of multiple entities, select the one that's closest (?)
					pathFinder_.findPath(npc, entity.coordinates());
				}

				if (interactionHandler_.canInteract(npc, entity))
				{
					interactionHandler_.handleInteraction(npc, entity);
				}
			}
		}
	}
}
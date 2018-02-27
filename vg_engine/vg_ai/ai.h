#pragma once

#include "../vg_data/actors2d.h"
#include "../vg_data/geometry2d.h"
#include <vector>

namespace AI
{
	class PathFinder
	{
	public:
		bool findPath(Actor2D::NPC & npc, const Geometry::Coordinates & goal);
	};

	class InteractionHandler
	{
	private:
		bool insideRange(Actor2D::NPC & npc, Geometry::Dimensions range, Actor2D::Entity & entity);
	public:
		bool canDetect(Actor2D::NPC & npc, Actor2D::Entity & entity);
		bool canInteract(Actor2D::NPC & npc, Actor2D::Entity & entity);
		void handleInteraction(Actor2D::NPC & npc, Actor2D::Entity entity);
	};

	class Coordinator
	{
	private:
		PathFinder pathFinder_;
		InteractionHandler interactionHandler_;
	public:
		Coordinator() : pathFinder_(), interactionHandler_() {};
		void resolveGoals(Actor2D::NPC &, std::vector<Actor2D::Entity>);
	};
}
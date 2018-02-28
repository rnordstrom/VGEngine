#include "actors2d.h"
#include "geometry2d.h"
#include <limits>

using Actor2D::Entity;
using Actor2D::NPC;
using Actor2D::GoalType;

using Geometry::Coordinates;
using Geometry::Dimensions;

using std::pair;
using std::numeric_limits;
using std::string;

using float_lim = numeric_limits<float>;

const std::string & Entity::getTextureFileName() const
{
	return textureFileName_;
}

bool Entity::operator==(const Entity & e) const
{
	if (coordinates_.x != e.coordinates_.x || coordinates_.y != e.coordinates_.y)
	{
		return false;
	}

	if (dimensions_.width != e.dimensions_.width || dimensions_.height != e.dimensions_.height)
	{
		return false;
	}

	if (angleOfRotation_ != e.angleOfRotation_)
	{
		return false;
	}

	if (textureFileName_ != e.textureFileName_)
	{
		return false;
	}

	return true;
}

void NPC::baseInit()
{
	Coordinates undefined{ float_lim::infinity(), float_lim::infinity() };

	goals_.push_back(pair<GoalType, Coordinates>(GoalType::interaction, undefined));
	goals_.push_back(pair<GoalType, Coordinates>(GoalType::location, undefined));

	// TODO: Settle on constants for these ranges, or make them adaptive
	detectionRange_ = Dimensions{ 256, 256 };
	interactionRange_ = Dimensions{ 128, 128 };
}

/*	Initializes an NPC with undefined goals and standard detection/interaction parameters */
NPC::NPC()
{
	baseInit();
}

NPC::NPC(Coordinates coordinates, Dimensions dimensions, float angleOfRotation, string textureFileName) :
	Entity(coordinates, dimensions, angleOfRotation, textureFileName) 
{
	baseInit();
}

void NPC::setGoalPriority(GoalType type, int priority)
{
	int zeroIndexedPrio = priority - 1;

	for (int i = 0; i < goals_.size(); i++)
	{
		auto goal = goals_.at(i);

		if (goal.first == type)
		{
			if (i == zeroIndexedPrio)
			{
				return;
			}
			else
			{
				goals_.erase(goals_.begin() + i);
				goals_.insert(goals_.begin() + zeroIndexedPrio, goal);
			}
		}
	}
}

const std::pair <GoalType, Geometry::Coordinates> & NPC::getGoalByType(GoalType type) const
{
	for (auto goal : goals_)
	{
		if (goal.first == type)
		{
			return goal;
		}
	}
}

void NPC::setGoalByType(GoalType type, const Geometry::Coordinates & coordinates)
{
	for (auto & goal : goals_)
	{
		if (goal.first == type)
		{
			goal.second = coordinates;
		}
	}
}


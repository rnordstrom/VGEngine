#pragma once
#include "geometry2d.h"
#include <string>
#include <memory>
#include <vector>

namespace Actor2D
{
	enum class GoalType { location, interaction };

	/*	Represents an abstract two-dimensional entity. Entities consist of their coordinates in 2D space,
		their rectangular dimensions, an angle of rotation and a concrete file name (or path) of a texture
		image. */
	class Entity
	{
	private:
		Geometry::Coordinates coordinates_;
		Geometry::Dimensions dimensions_;
		float angleOfRotation_;
		std::string textureFileName_;
	public:
		Entity() : 
			coordinates_{ 0, 0 }, 
			dimensions_{ 0, 0 }, 
			angleOfRotation_ { 0.0 },
			textureFileName_{ " " } {};
		Entity(const Geometry::Coordinates & coordinates, const Geometry::Dimensions & dimensions, float angleOfRotation, const std::string & textureFileName) :
			coordinates_{ coordinates }, 
			dimensions_{ dimensions }, 
			angleOfRotation_{ angleOfRotation },
			textureFileName_{ textureFileName } {};
		inline Geometry::Coordinates & coordinates() { return coordinates_; };
		inline Geometry::Dimensions & dimensions() { return dimensions_; };
		inline float getAngleOfRotation() { return angleOfRotation_; };
		inline void setAngleOfRotation(float angleOfRotation) { angleOfRotation_ = angleOfRotation; };
		const std::string & getTextureFileName() const;
		virtual bool operator==(const Entity &) const;
		virtual ~Entity() {};
	};

	/*	Encapsulates an Entity instance and provides engine-specific details */
	template <typename Texture, typename Sprite>
	class EntityWrapper
	{
	private:
		Actor2D::Entity entity_;
		std::shared_ptr<Texture> texture_;
		Sprite sprite_;
	public:
		EntityWrapper(const Actor2D::Entity & entity, const std::shared_ptr<Texture> & texture, const Sprite & sprite) :
			entity_{ entity }, 
			texture_{ texture }, 
			sprite_{ sprite } {};
		inline Actor2D::Entity & entity() { return entity_; };
		inline const std::shared_ptr<Texture> & getTexture() const { return texture_; };
		inline Sprite & sprite() { return sprite_; };
	};

	/*	Represents an abstract NPC. An NPC has a set of goals ordered strictly by numeric priority: {1, 2, ..., n};
		goals consist of a goal type and a set of coordinates in 2D space at which they can be reached by the NPC.
		NPCs are furthermore equipped with a rectangular range wherein they can detect a player or other NPCs, 
		and another rectangular range wherein they can interact with other entities. */
	class NPC : public Entity
	{
	private:
		std::vector<std::pair<GoalType, Geometry::Coordinates>> goals_;
		Geometry::Dimensions detectionRange_;
		Geometry::Dimensions interactionRange_;
	public:
		NPC();
		NPC(Geometry::Coordinates coordinates, Geometry::Dimensions dimensions, float angleOfRotation, std::string textureFileName) :
			Entity(coordinates, dimensions, angleOfRotation, textureFileName) {};
		inline const std::pair<GoalType, Geometry::Coordinates> & getGoalByPriority(int priority) const { return goals_.at(priority - 1); };
		void setGoalPriority(GoalType type, int priority);
		inline const std::pair <GoalType, Geometry::Coordinates> & getGoalByType(GoalType type) const
		{
			for (auto goal : goals_)
			{
				if (goal.first == type)
				{
					return goal;
				}
			}
		}
		inline void setGoalByType(GoalType type, const Geometry::Coordinates & coordinates)
		{
			for (auto & goal : goals_)
			{
				if (goal.first == type)
				{
					goal.second = coordinates;
				}
			}
		};
	};
}
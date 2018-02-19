#pragma once
#include "geometry2d.h"
#include <string>
#include <memory>

namespace Actor2D
{
	/*	Represents an abstract two-dimensional entity */
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

	/*	Encapsulates an Entity instance and provides engine-specific collisionDetails_ */
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
}
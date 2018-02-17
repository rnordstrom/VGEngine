#pragma once
#include "geometry2d.h"
#include <string>
#include <memory>

namespace Actor2D
{
	using Geometry::Coordinates;
	using Geometry::Dimensions;

	using std::string;
	using std::shared_ptr;

	/*	Represents an abstract two-dimensional entity */
	class Entity
	{
	private:
		Coordinates coordinates_;
		Dimensions dimensions_;
		float angleOfRotation_;
		string textureFileName_;
	public:
		Entity() : 
			coordinates_{ 0, 0 }, 
			dimensions_{ 0, 0 }, 
			angleOfRotation_ { 0.0 },
			textureFileName_{ " " } {};
		Entity(const Coordinates & coordinates, const Dimensions & dimensions, float angleOfRotation, const string & textureFileName) : 
			coordinates_{ coordinates }, 
			dimensions_{ dimensions }, 
			angleOfRotation_{ angleOfRotation },
			textureFileName_{ textureFileName } {};
		inline Coordinates & coordinates() { return coordinates_; };
		inline Dimensions & dimensions() { return dimensions_; };
		inline float getAngleOfRotation() { return angleOfRotation_; };
		inline void setAngleOfRotation(float angleOfRotation) { angleOfRotation_ = angleOfRotation; };
		const string & getTextureFileName() const;
		virtual bool operator==(const Entity &) const;
		virtual ~Entity() {};
	};

	/*	Encapsulates an Entity instance and provides engine-specific details */
	template <typename Texture, typename Sprite>
	class EntityWrapper
	{
	private:
		Entity entity_;
		shared_ptr<Texture> texture_;
		Sprite sprite_;
	public:
		EntityWrapper(const Entity & entity, const shared_ptr<Texture> & texture, const Sprite & sprite) : 
			entity_{ entity }, 
			texture_{ texture }, 
			sprite_{ sprite } {};
		inline Entity & entity() { return entity_; };
		inline const shared_ptr<Texture> & getTexture() const { return texture_; };
		inline Sprite & sprite() { return sprite_; };
	};
}
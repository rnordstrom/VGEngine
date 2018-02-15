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
	using std::unique_ptr;

	class Entity
	{
	private:
		Coordinates coordinates_;
		Dimensions dimensions_;
		string textureFileName_;
	public:
		Entity() : 
			coordinates_{ 0, 0 }, 
			dimensions_{ 0, 0 }, 
			textureFileName_{ " " } {};
		Entity(const Coordinates & coordinates, const Dimensions & dimensions, const string & textureFileName) : 
			coordinates_{ coordinates }, 
			dimensions_{ dimensions }, 
			textureFileName_{ textureFileName } {};
		inline const Coordinates & getCoordinates() const { return coordinates_; };
		inline void setCoordinates(const Coordinates & coordinates) { coordinates_ = coordinates; };
		inline const Dimensions & getDimensions() const { return dimensions_; };
		void setDimensions(const Dimensions & dimensions);
		const string & getTextureFileName() const;
		bool operator==(const Entity &) const;
	};

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
		inline const Entity & getEntity() const { return entity_; };
		inline const shared_ptr<Texture> & getTexture() const { return texture_; };
		inline Sprite getSprite() const { return sprite_; };
		inline void setSprite(const Sprite & newSprite) { sprite_ = newSprite; };
	};
}
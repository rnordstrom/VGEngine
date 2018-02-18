#pragma once
#include "../vg_data/actors2d.h"

namespace Physics2D
{
	using Actor2D::Entity;

	enum class HorizontalDirection{ left, right, none };
	enum class VerticalDirection{ above, below, none };

	/*	Holds information about the axis and direction of a collision */
	struct CollisionDetails
	{
		bool collisionX;
		bool collisionY;
		HorizontalDirection hDir;
		VerticalDirection vDir;
	};

	/* Detects collisions and reports collision details */
	class CollisionDetector
	{
	private:
		int screenWidth_;
		int screenHeight_;
		CollisionDetails collisionDetails_;
		inline void resetCollisionDetails()
		{
			collisionDetails_.collisionX = false;
			collisionDetails_.collisionY = false;
			collisionDetails_.hDir = HorizontalDirection::none;
			collisionDetails_.vDir = VerticalDirection::none;
		};
	public:
		CollisionDetector(int screenWidth, int screenHeight) : 
			screenWidth_{ screenWidth }, 
			screenHeight_{ screenHeight } {};
		bool detect(Entity);
		inline const CollisionDetails & getCollisionDetails() const { return collisionDetails_; };
		inline void setScreenWidth(int screenWidth) { screenWidth_ = screenWidth; };
		inline void setScreenHeight(int screenHeight) { screenHeight_ = screenHeight; };
	};

	/*	Moves an Entity across 2D space.
		TODO: Take an Entity's velocity into account with respect to movement. */
	class Motor
	{
	private:
		CollisionDetector collisionDetector_;
		inline void moveUp_(Entity & entity) { entity.coordinates().y -= 1; };
		void moveDown_(Entity & entity) { entity.coordinates().y += 1; };
		void moveLeft_(Entity & entity) { entity.coordinates().x -= 1; };
		void moveRight_(Entity & entity) { entity.coordinates().x += 1; };
	public:
		Motor(CollisionDetector detector) : collisionDetector_{ detector } {};
		void moveUp(Entity & entity);
		void moveDown(Entity & entity);
		void moveLeft(Entity & entity);
		void moveRight(Entity & entity);
	};
}
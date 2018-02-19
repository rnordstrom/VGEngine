#pragma once
#include "../vg_data/actors2d.h"

namespace Physics2D
{
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
		int windowWidth_;
		int windowHeight_;
		CollisionDetails collisionDetails_;
		inline void resetCollisionDetails()
		{
			collisionDetails_.collisionX = false;
			collisionDetails_.collisionY = false;
			collisionDetails_.hDir = HorizontalDirection::none;
			collisionDetails_.vDir = VerticalDirection::none;
		};
	public:
		CollisionDetector(int windowWidth, int windowHeight) : 
			windowWidth_{ windowWidth }, 
			windowHeight_{ windowHeight } {};
		bool detect(Actor2D::Entity);
		inline const CollisionDetails & getCollisionDetails() const { return collisionDetails_; };
		inline void setScreenWidth(int screenWidth) { windowWidth_ = screenWidth; };
		inline void setScreenHeight(int screenHeight) { windowHeight_ = screenHeight; };
	};

	/*	Moves an Entity across 2D space.
		TODO: Take an Entity's velocity into account with respect to movement. */
	class Motor
	{
	private:
		CollisionDetector collisionDetector_;
		inline void moveUp_(Actor2D::Entity & entity) { entity.coordinates().y -= 1.0; };
		void moveDown_(Actor2D::Entity & entity) { entity.coordinates().y += 1.0; };
		void moveLeft_(Actor2D::Entity & entity) { entity.coordinates().x -= 1.0; };
		void moveRight_(Actor2D::Entity & entity) { entity.coordinates().x += 1.0; };
	public:
		Motor(CollisionDetector detector) : collisionDetector_{ detector } {};
		void moveUp(Actor2D::Entity & entity);
		void moveDown(Actor2D::Entity & entity);
		void moveLeft(Actor2D::Entity & entity);
		void moveRight(Actor2D::Entity & entity);
	};
}
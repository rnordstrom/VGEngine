#include "pysics2d.h"

using Physics2D::HorizontalDirection;
using Physics2D::VerticalDirection;
using Physics2D::CollisionDetector;
using Physics2D::Motor;

using Actor2D::Entity;

/*	Determines if a collision has occurred between an Entity 
	and the horizontal/vertical limits of the window */
bool CollisionDetector::detect(Entity entity)
{
	resetCollisionDetails();
	bool collided = false;

	if (entity.coordinates().x < 0)
	{
		collisionDetails_.collisionX = true;
		collisionDetails_.hDir = HorizontalDirection::left;
		collided = true;
	}
	else if (entity.coordinates().x + entity.dimensions().width > screenWidth_)
	{
		collisionDetails_.collisionX = true;
		collisionDetails_.hDir = HorizontalDirection::right;
		collided = true;
	}

	if (entity.coordinates().y < 0)
	{
		collisionDetails_.collisionY = true;
		collisionDetails_.vDir = VerticalDirection::above;
		collided = true;
	}
	else if (entity.coordinates().y + entity.dimensions().height > screenHeight_)
	{
		collisionDetails_.collisionY = true;
		collisionDetails_.vDir = VerticalDirection::below;
		collided = true;
	}

	return collided;
}

/*	Moves an Entity upward. Subject to potential collision,
	which will prohibit movement in the desired direction. */
void Motor::moveUp(Entity & entity)
{
	if (!collisionDetector_.detect(entity))
	{
		moveUp_(entity);
	}
	else
	{
		CollisionDetails details = collisionDetector_.getCollisionDetails();

		if (details.collisionY && details.vDir == VerticalDirection::above)
		{
			moveDown_(entity);
		}
	}
}

/*	Moves an Entity downward. Subject to potential collision,
	which will prohibit movement in the desired direction. */
void Motor::moveDown(Entity & entity)
{
	if (!collisionDetector_.detect(entity))
	{
		moveDown_(entity);
	}
	else
	{
		CollisionDetails details = collisionDetector_.getCollisionDetails();

		if (details.collisionY && details.vDir == VerticalDirection::below)
		{
			moveUp_(entity);
		}
	}
}

/*	Moves an Entity to the left. Subject to potential collision,
	which will prohibit movement in the desired direction. */
void Motor::moveLeft(Entity & entity)
{
	if (!collisionDetector_.detect(entity))
	{
		moveLeft_(entity);
	}
	else
	{
		CollisionDetails details = collisionDetector_.getCollisionDetails();

		if (details.collisionX && details.hDir == HorizontalDirection::left)
		{
			moveRight_(entity);
		}
	}
}

/*	Moves an Entity to the right. Subject to potential collision,
	which will prohibit movement in the desired direction. */
void Motor::moveRight(Entity & entity)
{
	if (!collisionDetector_.detect(entity))
	{
		moveRight_(entity);
	}
	else
	{
		CollisionDetails details = collisionDetector_.getCollisionDetails();

		if (details.collisionX && details.hDir == HorizontalDirection::right)
		{
			moveLeft_(entity);
		}
	}
}


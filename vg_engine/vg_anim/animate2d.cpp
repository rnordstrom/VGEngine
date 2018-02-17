#include "animate2d.h"

using sf::Texture;
using sf::Sprite;

using Animate2D::Animator;

using Actor2D::EntityWrapper;
using Actor2D::Entity;

using Geometry::Coordinates;
using Geometry::Dimensions;

/*	Applies an Entity's physical changes to its sprite.
	TODO: Possible optimization -- check whether or not
	the Entity has changed since the last call to apply(). */
void Animator::apply(EntityWrapper<Texture, Sprite> & wrapper)
{
	Entity entity = wrapper.entity();
	Sprite sprite = wrapper.sprite();
	
	Coordinates coordinates = entity.coordinates();
	float angleOfRotation = entity.getAngleOfRotation();

	sprite.setPosition(sf::Vector2f(coordinates.x, coordinates.y));
	sprite.setRotation(angleOfRotation);

	renderer.drawSprite(sprite);
}
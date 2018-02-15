#include "actors2d.h"
#include "geometry2d.h"

using namespace Actor2D;
using namespace Geometry;

void Entity::setDimensions(const Dimensions & dimensions)
{
	dimensions_ = dimensions;
}

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

	if (textureFileName_ != e.textureFileName_)
	{
		return false;
	}

	return true;
}
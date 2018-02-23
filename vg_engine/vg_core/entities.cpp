#include "entities.h"
#include <memory>

using Registry::Role;
using Registry::EntityRegistry;

using Actor2D::Entity;
using Actor2D::EntityWrapper;

using sf::Texture;
using sf::Sprite;

using std::pair;
using std::shared_ptr;
using std::make_shared;
using std::vector;

EntityWrapper<Texture, Sprite> EntityRegistry::wrap(Entity & entity)
{
	shared_ptr<Texture> texturePtr = make_shared<Texture>();
	texturePtr->loadFromFile(entity.getTextureFileName());

	Sprite sprite;
	sprite.setTexture(*texturePtr);

	return EntityWrapper<Texture, Sprite>(entity, texturePtr, sprite);
}

void EntityRegistry::registerEntity(Entity & entity, Role role)
{
	EntityWrapper<Texture, Sprite> wrapper = wrap(entity);

	switch (role)
	{
	case Role::player:
		if (entityMap_.find(Role::player) != entityMap_.end())
		{
			entityMap_.erase(Role::player);
		}
		break;
	}

	entityMap_.insert(pair<Role, EntityWrapper<Texture, Sprite>>(role, wrapper));
}

vector<EntityWrapper<Texture, Sprite>> EntityRegistry::getByRole(Role role)
{
	auto range = entityMap_.equal_range(role);
	vector<EntityWrapper<Texture, Sprite>> vector;

	for (auto it = range.first; it != range.second; ++it)
	{
		vector.push_back(it->second);
	}

	return vector;
}


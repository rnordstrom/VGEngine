#pragma once

#include "../vg_data/actors2d.h"
#include <SFML/Graphics.hpp>
#include <map>
#include <vector>

namespace Registry
{
	enum class Role{ player };

	/*	Singleton class that manages and categorizes Entities */
	class EntityRegistry
	{
	private:
		std::multimap <Role, Actor2D::EntityWrapper<sf::Texture, sf::Sprite>> entityMap_;
		EntityRegistry() {};
		Actor2D::EntityWrapper<sf::Texture, sf::Sprite> wrap(Actor2D::Entity & entity);
	public:
		static EntityRegistry & getInstance()
		{
			static EntityRegistry instance;

			return instance;
		};
		void registerEntity(Actor2D::Entity & entity, Role role);
		std::vector<Actor2D::EntityWrapper<sf::Texture, sf::Sprite>> getByRole(Role role);
		EntityRegistry(const EntityRegistry &) = delete;
		void operator=(const EntityRegistry &) = delete;
	};
}
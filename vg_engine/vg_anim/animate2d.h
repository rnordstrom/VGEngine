#pragma once
#include <string>
#include "../vg_gfx/graphics2d.h"
#include "../vg_data/actors2d.h"

namespace Animate2D
{
	/*	Animates a two-dimensional Entity */
	class Animator
	{
	private:
		Render2D::Renderer renderer;
	public:
		explicit Animator(const std::string & windowTitle) : renderer{ windowTitle } {};
		void apply(Actor2D::EntityWrapper<sf::Texture, sf::Sprite> & wrapper);
		Render2D::Renderer & getRenderer() { return renderer; };
	};
}
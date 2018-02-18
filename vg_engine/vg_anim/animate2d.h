#pragma once
#include <string>
#include "../vg_gfx/graphics2d.h"
#include "../vg_data/actors2d.h"

namespace Animate2D
{
	using std::string;

	using sf::Texture;
	using sf::Sprite;

	using Render2D::Renderer;

	using Actor2D::EntityWrapper;

	/*	Animates a two-dimensional Entity */
	class Animator
	{
	private:
		Renderer renderer;
	public:
		explicit Animator(const string & title) : renderer{ title } {};
		void apply(EntityWrapper<Texture, Sprite> & wrapper);
		inline Renderer & getRenderer() { return renderer; };
	};
}
#pragma once
#include <string>
#include <SFML/Graphics.hpp>

namespace Render2D
{
	using sf::Sprite;
	using sf::RenderWindow;

	/*	Renders 2D sprites. */
	class Renderer
	{
	private:
		RenderWindow window;
	public:
		Renderer(const std::string & title, int width = 800, int height = 600);
		Renderer(const Renderer & r) = delete;
		inline void clearScreen() { window.clear(); };
		inline void displayFrame() { window.display(); };
		inline void drawSprite(const Sprite & sprite) { window.draw(sprite); };
		inline RenderWindow & getWindow() { return window; };
		void setVsync(bool b);
		Renderer & operator=(const Renderer & r) = delete;
	};
}
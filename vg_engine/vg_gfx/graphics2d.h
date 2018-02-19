#pragma once
#include <string>
#include <SFML/Graphics.hpp>

namespace Render2D
{
	/*	Renders 2D sprites. */
	class Renderer
	{
	private:
		sf::RenderWindow window_;
	public:
		Renderer(const std::string & title, int width = 800, int height = 600);
		Renderer(const Renderer & r) = delete;
		inline void clearScreen() { window_.clear(); };
		inline void displayFrame() { window_.display(); };
		inline void drawSprite(const sf::Sprite & sprite) { window_.draw(sprite); };
		inline bool windowIsOpen() { return window_.isOpen(); };
		inline bool pollWindowEvent(sf::Event & event) { return window_.pollEvent(event); };
		inline void closeWindow() { window_.close(); };
		void setVsync(bool b);
		Renderer & operator=(const Renderer & r) = delete;
	};
}
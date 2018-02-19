#include "input2d.h"

using sf::Texture;
using sf::Sprite;
using sf::Event;
using sf::Keyboard;

using Input2D::InputHandler;

using Actor2D::Entity;
using Actor2D::EntityWrapper;

void InputHandler::mapInput_(Entity & entity)
{
	if (Keyboard::isKeyPressed(sf::Keyboard::W))
	{
		motor_.moveUp(entity);
	}

	if (Keyboard::isKeyPressed(sf::Keyboard::S))
	{
		motor_.moveDown(entity);
	}

	if (Keyboard::isKeyPressed(sf::Keyboard::A))
	{
		motor_.moveLeft(entity);
	}

	if (Keyboard::isKeyPressed(sf::Keyboard::D))
	{
		motor_.moveRight(entity);
	}
}

void InputHandler::startInputLoop(EntityWrapper<Texture, Sprite> & playerWrapper)
{
	running_ = true;

	while (running_ && animator_.getRenderer().windowIsOpen())
	{
		Event event;

		while (animator_.getRenderer().pollWindowEvent(event))
		{
			if (event.type == sf::Event::Closed)
			{
				animator_.getRenderer().closeWindow();
			}
		}

		mapInput_(playerWrapper.entity());

		animator_.getRenderer().clearScreen();
		animator_.apply(playerWrapper);
		animator_.getRenderer().displayFrame();
	}
}
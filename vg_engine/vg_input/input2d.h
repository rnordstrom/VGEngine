#pragma once
#include <string>
#include "../vg_anim/animate2d.h"
#include "../vg_phys/pysics2d.h"
#include "../vg_data/actors2d.h"

namespace Input2D
{
	/*	Manages the input loop of a running application */
	class InputHandler
	{
	private:
		Animate2D::Animator animator_;
		Physics2D::Motor motor_;
		bool running_;
		void mapInput_(Actor2D::Entity & entity);
	public:
		InputHandler(std::string windowTitle, int windowWidth, int windowHeight) :
			animator_{ windowTitle },
			motor_{ Physics2D::CollisionDetector(windowWidth, windowHeight) },
			running_{ false } {};
		void startInputLoop();
		void stopInputLoop() { running_ = false; };
		bool loopIsRunning() { return running_; };
	};
}
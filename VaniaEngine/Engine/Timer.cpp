
#include "Engine.hpp"

/*------------------------------------------------------------------------------
< Constructor >
------------------------------------------------------------------------------*/
Timer::Timer() {

}


/*------------------------------------------------------------------------------
< Destructor >
------------------------------------------------------------------------------*/
Timer::~Timer() {

}


/*------------------------------------------------------------------------------
< start >
------------------------------------------------------------------------------*/
void Timer::start() {
	this->lastTime = glfwGetTime();
}


/*------------------------------------------------------------------------------
< set >
------------------------------------------------------------------------------*/
// in a game loop but not in FPS check loop
void Timer::setTime() {
	this->currentTime = glfwGetTime();
}


/*------------------------------------------------------------------------------
< update >
------------------------------------------------------------------------------*/
// in FPS check loop
void Timer::update() {
	this->currentTime = glfwGetTime();
	this->deltaTime = this->currentTime - this->lastTime;
	if (this->deltaTime > 0.04f) {
		this->deltaTime = 0.032f;
	}
	this->lastTime = this->currentTime;
}


/*------------------------------------------------------------------------------
< checkFPS >
------------------------------------------------------------------------------*/
bool Timer::checkFPS(int frameRate) {
	if (this->currentTime - this->lastTime >= 1.0f / frameRate) {
		return true;
	}
	else {
		return false;
	}
}

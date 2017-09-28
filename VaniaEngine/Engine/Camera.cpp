
#include "Engine.hpp"

/*------------------------------------------------------------------------------
< Constructor >
------------------------------------------------------------------------------*/
Camera::Camera() {
	this->window = getWindow();
	this->projection = glm::ortho(-this->window->screenWidth/2.0f, this->window->screenWidth/2.0f, -this->window->screenHeight/2.0f, this->window->screenHeight/2.0f, 0.0f, 100.0f);
	this->startScreenWidth = this->window->screenWidth;
	this->startScreenHeight = this->window->screenHeight;
}


/*------------------------------------------------------------------------------
< Destructor >
------------------------------------------------------------------------------*/
Camera::~Camera() {

}


/*------------------------------------------------------------------------------
< update > after GameObject fixedUpdate() before Camera updateUniform()
------------------------------------------------------------------------------*/
void Camera::updatePosition() {
	// Camera position
	if (this->target != nullptr) {
		if (!this->switching) {
			this->position.x = this->target->transform->position.x;
			this->position.y = this->target->transform->position.y;
		}
		else {
			if (this->position.x != this->target->transform->position.x) {
				if (this->position.x > this->target->transform->position.x) {
					this->position.x -= this->switchSpeed * getGame()->timer->deltaTime;
					if (this->position.x < this->target->transform->position.x) {
						this->position.x = this->target->transform->position.x;
					}
				}
				else {
					this->position.x += this->switchSpeed * getGame()->timer->deltaTime;
					if (this->position.x > this->target->transform->position.x) {
						this->position.x = this->target->transform->position.x;
					}
				}
			}
			if (this->position.x == this->target->transform->position.x) {
				this->switching = false;
			}
		}
	}
}


/*------------------------------------------------------------------------------
< update > after Camera updatePosition() maybe after Scene fixCamera() before GameObject draw()
------------------------------------------------------------------------------*/
void Camera::updateUniform() {
  this->window->getWindowSize();
	// update uniform
	this->projection = glm::ortho(-this->window->screenWidth/2.0f, this->window->screenWidth/2.0f, -this->window->screenHeight/2.0f, this->window->screenHeight/2.0f, 0.0f, 100.0f);
	this->view = glm::lookAt(
		glm::vec3(this->position.x * PIXEL_SCALE * UNIT_TO_PIXEL * this->window->retina + (this->window->screenWidth - this->startScreenWidth) / 2.0f, this->position.y * PIXEL_SCALE * UNIT_TO_PIXEL * this->window->retina + (this->window->screenHeight - this->startScreenHeight) / 2.0f , this->position.z), // camera position
		glm::vec3(this->position.x * PIXEL_SCALE * UNIT_TO_PIXEL * this->window->retina + (this->window->screenWidth - this->startScreenWidth) / 2.0f, this->position.y * PIXEL_SCALE * UNIT_TO_PIXEL * this->window->retina + (this->window->screenHeight - this->startScreenHeight) / 2.0f , 0), // target position
		glm::vec3(0,1,0)  // up
	);
}


/*------------------------------------------------------------------------------
< switchTarget >
------------------------------------------------------------------------------*/
void Camera::switchTarget(GameObject* target) {
	if (!this->switching) {
		this->switching = true;
		this->target = target;
	}
}



	// // Scene Camera Range
	// if (this->position.x <= this->range[2*this->activeRange]->transform->position.x) {
	// 	this->position.x = this->range[2*this->activeRange]->transform->position.x;
	// }
	// if (this->position.x > this->range[2*this->activeRange + 1]->transform->position.x) {
	// 	this->position.x = this->range[2*this->activeRange + 1]->transform->position.x;
	// }
	// if (this->position.y <= this->range[2*this->activeRange]->transform->position.y) {
	// 	this->position.y = this->range[2*this->activeRange]->transform->position.y;
	// }
	// if (this->position.y > this->range[2*this->activeRange + 1]->transform->position.y) {
	// 	this->position.y = this->range[2*this->activeRange + 1]->transform->position.y;
	// }

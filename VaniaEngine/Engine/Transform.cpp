
#include "Engine.hpp"

/*------------------------------------------------------------------------------
< Constructor >
------------------------------------------------------------------------------*/
Transform::Transform() {
	this->window = getWindow();
}


/*------------------------------------------------------------------------------
< Destructor >
------------------------------------------------------------------------------*/
Transform::~Transform() {

}


/*------------------------------------------------------------------------------
< update > in GameObject draw()
------------------------------------------------------------------------------*/
void Transform::update() {
	this->model = glm::mat4();
	this->model = glm::rotate(this->rotation.z,glm::vec3(0,0,1));
	this->model = glm::scale(this->model, glm::vec3(this->scale.x * PIXEL_SCALE, this->scale.y * PIXEL_SCALE, this->scale.z));
	this->model = glm::translate(this->model, glm::vec3(this->position.x / this->scale.x * UNIT_TO_PIXEL * this->window->retina, this->position.y / this->scale.y * UNIT_TO_PIXEL * this->window->retina, this->position.z));
}

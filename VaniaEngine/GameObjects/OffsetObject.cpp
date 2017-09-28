
#include "Engine.hpp"

/*------------------------------------------------------------------------------
< Constructor >
------------------------------------------------------------------------------*/
OffsetObject::OffsetObject(GameObject* parent, float x, float y) {
	// GameObject setting
	this->visible = false;
	// offset setting
	this->parent = parent;
	this->offset.x = x;
	this->offset.y = y;
}


/*------------------------------------------------------------------------------
< Destructor >
------------------------------------------------------------------------------*/
OffsetObject::~OffsetObject() {

}


/*------------------------------------------------------------------------------
< Start >
------------------------------------------------------------------------------*/
void OffsetObject::start() {
	// set sprite texture and slice | Animation start
}


/*------------------------------------------------------------------------------
< update >
------------------------------------------------------------------------------*/
void OffsetObject::update() {
	/* Animation update sprite
	..............................................................................*/
}


/*------------------------------------------------------------------------------
< onTriggerEnter >
------------------------------------------------------------------------------*/
void OffsetObject::onTriggerEnter(BoxCollider* other) {

}


/*------------------------------------------------------------------------------
< fixedUpdate >
------------------------------------------------------------------------------*/
void OffsetObject::fixedUpdate() {
	this->transform->position.x = this->parent->transform->position.x + this->offset.x;
	this->transform->position.y = this->parent->transform->position.y + this->offset.y;
	this->transform->position.z = this->parent->transform->position.z;
}

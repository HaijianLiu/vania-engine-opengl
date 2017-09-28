
#include "Engine.hpp"

/*------------------------------------------------------------------------------
< Constructor >
------------------------------------------------------------------------------*/
BoxCollider::BoxCollider(GameObject* gameObject, float x, float y, float w, float h) {
	this->colliders = getGame()->getColliders();
	this->colliders->push_back(this);

	this->gameObject = gameObject;
	this->offset.x = x;
	this->offset.y = y;
	this->size.x = w;
	this->size.y = h;
	this->halfSize.x = w / 2.0f;
	this->halfSize.y = h / 2.0f;
}


/*------------------------------------------------------------------------------
< Destructor >
------------------------------------------------------------------------------*/
BoxCollider::~BoxCollider() {

}

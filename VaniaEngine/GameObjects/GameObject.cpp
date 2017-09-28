
#include "Engine.hpp"

/*------------------------------------------------------------------------------
< Constructor >
------------------------------------------------------------------------------*/
GameObject::GameObject() {
	// GetGameObjects and push_back
	this->gameObjects = getGame()->getGameObjects();
	this->gameObjects->push_back(this);
	// new GameObject members
	this->transform = new Transform();
	this->sprite = new Sprite();
	this->sprite->gameObject = this;
	this->status = new Status();
}


/*------------------------------------------------------------------------------
< Destructor >
------------------------------------------------------------------------------*/
GameObject::~GameObject() {
	delete this->transform;
	delete this->sprite;
	delete this->status;
}


/*------------------------------------------------------------------------------
< preStart > before GameObject start() & after Resources start()
------------------------------------------------------------------------------*/
void GameObject::defaultStart() {
	// get birthtime
	this->status->birthTime = getGame()->timer->currentTime;
	// sprite start
	this->sprite->start();
}


/*------------------------------------------------------------------------------
< draw >
------------------------------------------------------------------------------*/
void GameObject::draw() {
	// transform update
	this->transform->update();
	// sprite draw
	this->sprite->draw();
}


/*------------------------------------------------------------------------------
< fixedUpdate >
------------------------------------------------------------------------------*/
void GameObject::fixedUpdate() {

}


/*------------------------------------------------------------------------------
< UIUpdate >
------------------------------------------------------------------------------*/
void GameObject::UIUpdate() {

}


/*------------------------------------------------------------------------------
< reset >
------------------------------------------------------------------------------*/
void GameObject::reset() {

}

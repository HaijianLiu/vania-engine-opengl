
#include "Engine.hpp"

/*------------------------------------------------------------------------------
< Constructor >
------------------------------------------------------------------------------*/
Particle::Particle() {
	// GameObject setting
	this->active = false;
	this->transform->position.z = 5.0f;
	// scale in real pixel
	this->transform->scale = glm::vec3(4.0f,4.0f,1.0f);
}


/*------------------------------------------------------------------------------
< Destructor >
------------------------------------------------------------------------------*/
Particle::~Particle() {

}


/*------------------------------------------------------------------------------
< start >
------------------------------------------------------------------------------*/
void Particle::start() {
	// set sprite texture and slice | Animation start
}


/*------------------------------------------------------------------------------
< update >
------------------------------------------------------------------------------*/
void Particle::update() {
	/* Destroy
	..............................................................................*/
	destroyByTime(this, this->startLifeTime);

	/* Transform
	..............................................................................*/
	this->transform->position.x += cos(this->startAngle) * this->startSpeed * getGame()->timer->deltaTime;
	this->transform->position.y += sin(this->startAngle) * this->startSpeed * getGame()->timer->deltaTime;

	/* Size Over LifeTime
	..............................................................................*/
	if (this->sizeOverLifeTime) {
		this->transform->scale.x -= this->startSize / this->startLifeTime * getGame()->timer->deltaTime;
		this->transform->scale.y -= this->startSize / this->startLifeTime * getGame()->timer->deltaTime;
	}

	/* gravity
	..............................................................................*/
	if (this->gravity != 0.0f) {
		this->verticalSpeed -= this->gravity * getGame()->timer->deltaTime;
		this->transform->position.y -= this->verticalSpeed * getGame()->timer->deltaTime;
	}
}


/*------------------------------------------------------------------------------
< onTriggerEnter >
------------------------------------------------------------------------------*/
void Particle::onTriggerEnter(BoxCollider* other) {

}


/*------------------------------------------------------------------------------
< instantiate >
------------------------------------------------------------------------------*/
void Particle::instantiate(Transform* transform) {
	this->active = true;
	this->status->birthTime = getGame()->timer->currentTime;
	this->transform->position.x = transform->position.x;
	this->transform->position.y = transform->position.y;
	this->startAngle = randomRange(this->startAngleRange.x, this->startAngleRange.y);
	this->startLifeTime = randomRange(this->startLifeTimeRange.x, this->startLifeTimeRange.y);
	this->startSpeed = randomRange(this->startSpeedRange.x, this->startSpeedRange.y);
	this->startSize = randomRange(this->startSizeRange.x, this->startSizeRange.y) * UNIT_TO_PIXEL;
	this->verticalSpeed = 0.0f;
	this->transform->scale = glm::vec3(this->startSize, this->startSize, 1.0f);
}

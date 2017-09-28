
#include "Engine.hpp"

/*------------------------------------------------------------------------------
< Constructor >
------------------------------------------------------------------------------*/
ParticleSystem::ParticleSystem(unsigned int size) {
	for (unsigned int i = 0; i < size; i++) {
		this->particles.push_back(new Particle());
	}
}


/*------------------------------------------------------------------------------
< Destructor >
------------------------------------------------------------------------------*/
ParticleSystem::~ParticleSystem() {
	deleteVector(this->particles);
}


/*------------------------------------------------------------------------------
< setTexture >
------------------------------------------------------------------------------*/
void ParticleSystem::setTexture(const char* name) {
	Resources* resources = getGame()->resources;
	for (unsigned int i = 0; i < this->particles.size(); i++) {
		this->particles[i]->sprite->texture = resources->getTexture(name);
	}
}


/*------------------------------------------------------------------------------
< instantiate >
------------------------------------------------------------------------------*/
void ParticleSystem::instantiate(Transform* transform) {
	if (this->rateOverTime) {
		int counter = 0;
		for (unsigned int i = 0; i < this->particles.size(); i++) {
			if (!this->particles[i]->active) {
				this->particles[i]->instantiate(transform);
				counter++;
				if (counter >= this->rate) {
					break;
				}
			}
		}
	}
	else {
		for (unsigned int i = 0; i < this->particles.size(); i++) {
			if (!this->particles[i]->active) {
				this->particles[i]->instantiate(transform);
				break;
			}
		}
	}
}


/*------------------------------------------------------------------------------
< set ParticleSystem >
------------------------------------------------------------------------------*/
void ParticleSystem::setStartLifeTimeRange(float min, float max) {
	for (unsigned int i = 0; i < this->particles.size(); i++) {
		this->particles[i]->startLifeTimeRange = glm::vec2(min, max);
	}
}
void ParticleSystem::setStartSpeedRange(float min, float max) {
	for (unsigned int i = 0; i < this->particles.size(); i++) {
		this->particles[i]->startSpeedRange = glm::vec2(min, max);
	}
}
void ParticleSystem::setStartSizeRange(float min, float max) {
	for (unsigned int i = 0; i < this->particles.size(); i++) {
		this->particles[i]->startSizeRange = glm::vec2(min, max);
	}
}
void ParticleSystem::setStartAngleRange(float min, float max) {
	for (unsigned int i = 0; i < this->particles.size(); i++) {
		this->particles[i]->startAngleRange = glm::vec2(min, max);
	}
}
void ParticleSystem::setGravity(float gravity) {
	for (unsigned int i = 0; i < this->particles.size(); i++) {
		this->particles[i]->gravity = gravity;
	}
}
void ParticleSystem::setColor(float r, float g, float b, float a) {
	for (unsigned int i = 0; i < this->particles.size(); i++) {
		this->particles[i]->sprite->setColor(r,g,b,a);
	}
}

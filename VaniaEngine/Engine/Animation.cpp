
#include "Engine.hpp"

/*------------------------------------------------------------------------------
< Constructor >
------------------------------------------------------------------------------*/
Animation::Animation(const char* textureName, float divideX, float divideY, float sampleTime) {
	// get
	this->timer = getGame()->timer;
	this->resources = getGame()->resources;
	// set parameters
	this->textureName = textureName;
	this->divide.x = divideX;
	this->divide.y = divideY;
	this->sampleTime = sampleTime;
}


/*------------------------------------------------------------------------------
< Destructor >
------------------------------------------------------------------------------*/
Animation::~Animation() {

}


/*------------------------------------------------------------------------------
< start > in GameObject start()
------------------------------------------------------------------------------*/
void Animation::start() {
	// load texture
	this->texture = this->resources->getTexture(this->textureName);
	// set slices
	this->sliceSize = glm::vec2(this->texture->width / this->divide.x, this->texture->height / this->divide.y);
	this->sliceMax = this->divide.x * this->divide.y;
	for (int i = 0; i < this->sliceMax; i++) {
		glm::mat3 slice = {
			this->sliceSize.x / this->texture->width, 0.0f, 0.0f,
			0.0f, this->sliceSize.y / this->texture->height, 0.0f,
			(i % (int)this->divide.x) * this->sliceSize.x / this->texture->width, (i / (int)this->divide.x) * this->sliceSize.y / this->texture->height, 1.0f,
		};
		this->slices.push_back(slice);
	}
}


/*------------------------------------------------------------------------------
< update > in GameObject update()
------------------------------------------------------------------------------*/
void Animation::update(Sprite* sprite) {
	// sampleTime per 1/60 seconds
	if (this->timer->currentTime > this->lastTime + this->sampleTime / 60.f) {
		this->currentSlice = (this->currentSlice + 1) % this->sliceMax;
		this->lastTime = this->timer->currentTime;
	}
	// update sprite
	sprite->texture = this->texture;
	sprite->slice = this->slices[this->currentSlice];
}

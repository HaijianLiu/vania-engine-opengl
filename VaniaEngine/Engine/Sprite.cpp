
#include "Engine.hpp"

/*------------------------------------------------------------------------------
< Constructor >
------------------------------------------------------------------------------*/
Sprite::Sprite() {

}


/*------------------------------------------------------------------------------
< Destructor >
------------------------------------------------------------------------------*/
Sprite::~Sprite() {

}


/*------------------------------------------------------------------------------
< start > in GameObject defaultStart()
------------------------------------------------------------------------------*/
void Sprite::start() {
	// sprite get default resources
	this->quad = getGame()->resources->quad;
	this->texture = getGame()->resources->getTexture("default");
	// sprite shader setting
	this->shader = getGame()->resources->getShader("SpriteFlash");
	this->shader->use();
	this->shader->setMat4("projection",getGame()->camera->projection);
	this->shader->setInt("texColor", 0);

	this->shader = getGame()->resources->getShader("Sprite");
	this->shader->use();
	this->shader->setMat4("projection",getGame()->camera->projection);
	this->shader->setInt("texColor", 0);
}


/*------------------------------------------------------------------------------
< draw > in GameObject update()
------------------------------------------------------------------------------*/
void Sprite::draw() {
	this->effect();
	// shader
	this->shader->use();
	// transform
	this->shader->setMat4("projection",getGame()->camera->projection);
	this->shader->setMat4("view", getGame()->camera->view);
	this->shader->setMat4("model", this->gameObject->transform->model);
	// slice
	this->shader->setMat3("slice", this->slice);
	// flip
	if (this->flipX) this->shader->setMat3("flip", this->matFlipX);
	else this->shader->setMat3("flip", glm::mat3(1.0f));
	// color
	this->shader->setVec4("spriteColor", this->color);
	// texture
	glActiveTexture(GL_TEXTURE0);
	glBindTexture(GL_TEXTURE_2D, this->texture->textureID);
	// draw
	this->quad->draw();
}


/*------------------------------------------------------------------------------
< setSlice >
------------------------------------------------------------------------------*/
void Sprite::setSlice(float offsetX, float offsetY, float sizeX, float sizeY) {
	this->slice = {
		sizeX / this->texture->width, 0.0f, 0.0f,
		0.0f, sizeY / this->texture->height, 0.0f,
		offsetX / this->texture->width, offsetY / this->texture->height, 1.0f,
	};
}


/*------------------------------------------------------------------------------
< setColor >
------------------------------------------------------------------------------*/
void Sprite::setColor(float r, float g, float b, float a) {
	this->color = glm::vec4(r / 255.0f, g / 255.0f, b / 255.0f, a / 255.0f);
}


/*------------------------------------------------------------------------------
< effect >
------------------------------------------------------------------------------*/
void Sprite::effect() {
	if (this->flashing) {
		if (getGame()->timer->currentTime < this->startEffect + this->flashTime) {
			if (sin(getGame()->timer->currentTime * 40) > 0) {
				this->shader = getGame()->resources->getShader("SpriteFlash");
			}
			else {
				this->shader = getGame()->resources->getShader("Sprite");
			}
		}
		else {
			this->flashing = false;
			this->shader = getGame()->resources->getShader("Sprite");
		}
	}
}

void Sprite::flash(float duration) {
	this->flashTime = duration;
	this->flashing = true;
	this->startEffect = getGame()->timer->currentTime;
}

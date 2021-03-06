
#include "Engine.hpp"

/*------------------------------------------------------------------------------
< Constructor >
------------------------------------------------------------------------------*/
Resources::Resources() {
	this->quad = new Quad();
	// start the sound engine with default parameters
	this->iSoundEngine = irrklang::createIrrKlangDevice();
	if (!this->iSoundEngine) printf("Could not startup engine\n");
}


/*------------------------------------------------------------------------------
< Destructor >
------------------------------------------------------------------------------*/
Resources::~Resources() {
	delete this->quad;
	deleteMap(this->textures);
	deleteMap(this->shaders);
	this->iSoundEngine->drop(); // delete engine
}


/*------------------------------------------------------------------------------
< start > before GameObject defaultStart()
------------------------------------------------------------------------------*/
void Resources::start() {

	/* Shader
	..............................................................................*/
	Resources::loadShader("Sprite", "./Assets/Shaders/Sprite.vs.glsl",  "./Assets/Shaders/Sprite.fs.glsl");
	Resources::loadShader("SpriteFlash", "./Assets/Shaders/Sprite.vs.glsl",  "./Assets/Shaders/SpriteFlash.fs.glsl");
	Resources::loadShader("RenderPass", "./Assets/Shaders/RenderPass.vs.glsl",  "./Assets/Shaders/RenderPass.fs.glsl");

	/* Texture
	..............................................................................*/
	Resources::loadTexture("default", "./Assets/Textures/default_16x16.png");

	/* Audio
	..............................................................................*/
}


/*------------------------------------------------------------------------------
< Load & Get >
------------------------------------------------------------------------------*/
void Resources::loadShader(const char* name, const char* vertexPath, const char* fragmentPath) {
	this->shaders.insert(std::make_pair(name, new Shader(vertexPath,fragmentPath)));
}
Shader* Resources::getShader(const char* name) {
	return this->shaders[name];
}
void Resources::loadTexture(const char* name, const char* path) {
	this->textures.insert(std::make_pair(name, new Texture(path)));
}
Texture* Resources::getTexture(const char* name) {
	return this->textures[name];
}
void Resources::loadAudio(const char* name, const char* path) {
	this->audios.insert(std::make_pair(name, new Audio(path)));
}
Audio* Resources::getAudio(const char* name) {
	return this->audios[name];
}

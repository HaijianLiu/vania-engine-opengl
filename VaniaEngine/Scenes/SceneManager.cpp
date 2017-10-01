
#include "Engine.hpp"

/*------------------------------------------------------------------------------
< Constructor >
------------------------------------------------------------------------------*/
SceneManager::SceneManager() {

}


/*------------------------------------------------------------------------------
< Destructor >
------------------------------------------------------------------------------*/
SceneManager::~SceneManager() {
	deleteMap(this->scenes);
}


/*------------------------------------------------------------------------------
< start >
------------------------------------------------------------------------------*/
void SceneManager::start() {
	// create Scenes
	this->createScene("Scene00", new Scene00());
	// start Scenes
	for (std::map<const char*, Scene*>::iterator it = this->scenes.begin(); it != this->scenes.end(); it++) {
		it->second->start();
	}
	// set active Scene
	SceneManager::setActiveScene("Scene00");
}


/*------------------------------------------------------------------------------
< update >
------------------------------------------------------------------------------*/
void SceneManager::update() {
	if (this->scenes.find(this->activeScene) != this->scenes.end()) {
		this->scenes[this->activeScene]->check();
		this->scenes[this->activeScene]->update();
	}
}


/*------------------------------------------------------------------------------
< creat Scene >
------------------------------------------------------------------------------*/
void SceneManager::createScene(const char* name, Scene* scene) {
	this->scenes.insert(std::make_pair(name, scene));
}


/*------------------------------------------------------------------------------
< set active Scene >
------------------------------------------------------------------------------*/
void SceneManager::setActiveScene(const char* name) {
	// if (this->scenes[this->activeScene]->bgm != nullptr && this->scenes[this->activeScene]->bgm->Playing()) {
	// 	this->scenes[this->activeScene]->bgm->Stop();
	// }
	this->activeScene = name;
	this->scenes[this->activeScene]->tiledMap->reset();
	this->scenes[this->activeScene]->frameSkip = true;
	this->scenes[this->activeScene]->reset();
	if (this->scenes[this->activeScene]->bgm == nullptr) {
//    getGame()->resources->iSoundEngine->stopAllSounds();
	}
	// if (this->scenes[this->activeScene]->bgm != nullptr) {
	// 	this->scenes[this->activeScene]->bgm->Play();
	// }
}

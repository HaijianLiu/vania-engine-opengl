
#include "Engine.hpp"

/*------------------------------------------------------------------------------
< Constructor >
------------------------------------------------------------------------------*/
Scene::Scene() {
	// TiledMap
	this->tiledMap = new TiledMap();
}


/*------------------------------------------------------------------------------
< Destructor >
------------------------------------------------------------------------------*/
Scene::~Scene() {
	// delete Map GameObjects
	delete this->tiledMap;
}


/*------------------------------------------------------------------------------
< Start > after Resources start()
------------------------------------------------------------------------------*/
void Scene::start() {
	/* get GameObjects and Colliders in initial Game
	..............................................................................*/
	std::vector<GameObject*>* gpGameObjects = getGame()->getGameObjects();
	std::vector<BoxCollider*>* gpColliders = getGame()->getColliders();
	unsigned int startGameObjectsSize = gpGameObjects->size();
	unsigned int startCollidersSize = gpColliders->size();


	/* load Scene
	..............................................................................*/
	this->load();


	/* create gameObjects
	..............................................................................*/
	// tiledMap GameObjects
	for (std::map<const char*, std::vector<glm::i32vec2>>::iterator it = this->tiledMap->mapDatas.begin(); it != this->tiledMap->mapDatas.end(); it++) {
		this->tiledMap->createGameObject(it->first);
	}


	/* Get GameObject && Get Collider
	..............................................................................*/
	this->gameObjects = getGame()->copyGameObjects();
	this->colliders = getGame()->copyColliders();
	// reset global gameObjects
	unsigned int size;
	size = gpGameObjects->size() - startGameObjectsSize;
	for (int i = 0; i < size; i++) {
		gpGameObjects->pop_back();
	}
	size = gpColliders->size() - startCollidersSize;
	for (int i = 0; i < size; i++) {
		gpColliders->pop_back();
	}


	/* gameObjects defaultStart() & start()
	..............................................................................*/
	for (unsigned int i = this->gameObjects.size(); i > 0; i--) {
		this->gameObjects[i-1]->defaultStart();
	}


	/* set objects position & slice (after given a texture)
	..............................................................................*/
	for (std::map<const char*, std::vector<glm::i32vec2>>::iterator it = this->tiledMap->mapDatas.begin(); it != this->tiledMap->mapDatas.end(); it++) {
		this->tiledMap->setGameObject(it->first);
	}

	this->set();

	/* gameObjects defaultStart() & start()
	..............................................................................*/
	for (unsigned int i = this->gameObjects.size(); i > 0; i--) {
		this->gameObjects[i-1]->start();
	}
}


/*------------------------------------------------------------------------------
< Update > GameObject update() onTriggerEnter() fixedUpdate() draw()
------------------------------------------------------------------------------*/
void Scene::update() {
	for (unsigned int i = 0; i < this->gameObjects.size(); i++) {
		if (this->gameObjects[i]->active) {
			this->gameObjects[i]->update();
		}
	}

	Scene::checkCollider();

	for (unsigned int i = 0; i < this->gameObjects.size(); i++) {
		if (this->gameObjects[i]->active) {
			this->gameObjects[i]->fixedUpdate();
		}
	}

	Scene::fixCamera("CameraRange");

	for (unsigned int i = 0; i < this->gameObjects.size(); i++) {
		if (this->gameObjects[i]->active) {
			this->gameObjects[i]->UIUpdate();
		}
	}

	// update backgrounds

	if (!this->frameSkip) {
		for (unsigned int i = this->gameObjects.size(); i > 0; i--) {
			if (this->gameObjects[i-1]->active && this->gameObjects[i-1]->visible) {
				this->gameObjects[i-1]->draw();
			}
		}
	}
	else {
		this->frameSkip = false;
	}

	// BGM
	if (this->bgm != nullptr && !this->bgm->playing()) {
//    getGame()->resources->iSoundEngine->stopAllSounds();
		this->bgm->play();
	}
}


/*------------------------------------------------------------------------------
< setBackground >
------------------------------------------------------------------------------*/
void Scene::setBackground(unsigned int id, const char* textureName) {
	
}


/*------------------------------------------------------------------------------
< setBGM >
------------------------------------------------------------------------------*/
void Scene::setBGM(const char* name) {
	this->bgm = getGame()->resources->getAudio(name);
	this->bgm->loop = true;
}


/*------------------------------------------------------------------------------
< CheckCollision >
------------------------------------------------------------------------------*/
bool Scene::checkCollision(BoxCollider* a, BoxCollider* b) {
	// Collision x-axis?
	bool collisionX =
		a->gameObject->transform->position.x + a->offset.x + a->halfSize.x * PIXEL_TO_UNIT >
		b->gameObject->transform->position.x + b->offset.x - b->halfSize.x * PIXEL_TO_UNIT
		&&
		a->gameObject->transform->position.x + a->offset.x - a->halfSize.x * PIXEL_TO_UNIT <
		b->gameObject->transform->position.x + b->offset.x + b->halfSize.x * PIXEL_TO_UNIT;
	// Collision y-axis?
	bool collisionY =
		a->gameObject->transform->position.y + a->offset.y + a->halfSize.y * PIXEL_TO_UNIT >
		b->gameObject->transform->position.y + b->offset.y - b->halfSize.y * PIXEL_TO_UNIT
		&&
		a->gameObject->transform->position.y + a->offset.y - a->halfSize.y * PIXEL_TO_UNIT <
		b->gameObject->transform->position.y + b->offset.y + b->halfSize.y * PIXEL_TO_UNIT;
	// Collision only if on both axes
	return collisionX && collisionY;
}
void Scene::checkCollider() {
	for (unsigned int i = 0; i < this->colliders.size(); i++) {
		if (this->colliders[i]->trigger && this->colliders[i]->gameObject->active && this->colliders[i]->active) {
			for (unsigned int j = 0; j < this->colliders.size(); j++) {
				bool collision = checkCollision(this->colliders[i],this->colliders[j]);
				if (i != j && collision && this->colliders[j]->gameObject->active && this->colliders[j]->active) {
					this->colliders[i]->enter = true;
					this->colliders[i]->gameObject->onTriggerEnter(this->colliders[j]);
					this->colliders[i]->enter = false;
					this->colliders[j]->enter = true;
					this->colliders[j]->gameObject->onTriggerEnter(this->colliders[i]);
					this->colliders[j]->enter = false;
				}
			}
		}
	}
}



/*------------------------------------------------------------------------------
< fix Camera > after Camera updatePosition() before Camera updateUniform()
------------------------------------------------------------------------------*/
void Scene::fixCamera(const char* name) {
	Camera* camera = getGame()->camera;

	camera->updatePosition();

	if (this->tiledMap->gameObjects.find(name) != this->tiledMap->gameObjects.end()) {
		if (this->tiledMap->gameObjects[name].size() == 1) {
			camera->position.x = this->tiledMap->gameObjects[name][0]->transform->position.x;
			camera->position.y = this->tiledMap->gameObjects[name][0]->transform->position.y;
		}
		if (this->tiledMap->gameObjects[name].size() == 2) {
			if (camera->position.x <= this->tiledMap->gameObjects[name][0]->transform->position.x) {
				camera->position.x = this->tiledMap->gameObjects[name][0]->transform->position.x;
			}
			if (camera->position.x > this->tiledMap->gameObjects[name][1]->transform->position.x) {
				camera->position.x = this->tiledMap->gameObjects[name][1]->transform->position.x;
			}
			if (camera->position.y <= this->tiledMap->gameObjects[name][0]->transform->position.y) {
				camera->position.y = this->tiledMap->gameObjects[name][0]->transform->position.y;
			}
			if (camera->position.y > this->tiledMap->gameObjects[name][1]->transform->position.y) {
				camera->position.y = this->tiledMap->gameObjects[name][1]->transform->position.y;
			}
		}
	}

	camera->updateUniform();
}


/*------------------------------------------------------------------------------
< reset > in sceneManager setActiveScene()
------------------------------------------------------------------------------*/
void Scene::reset() {

}

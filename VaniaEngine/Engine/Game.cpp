
#include "Engine.hpp"

/*------------------------------------------------------------------------------
< Constructor >
------------------------------------------------------------------------------*/
Game::Game() {
	// create engine objects
	this->timer = new Timer();
	this->camera = new Camera();
	this->resources = new Resources();
	this->sceneManager = new SceneManager();
}


/*------------------------------------------------------------------------------
< Destructor >
------------------------------------------------------------------------------*/
Game::~Game() {
	delete this->timer;
	delete this->camera;
	delete this->resources;
	delete this->sceneManager;
	delete this->player;
}


/*------------------------------------------------------------------------------
< start >
------------------------------------------------------------------------------*/
void Game::start() {
	// random seed
	srand((unsigned)this->timer->currentTime);
	// create GameObjects
	this->player = new Player();
	// ParticleSystem
	this->particleSystems.insert(std::make_pair("fx_tail", new ParticleSystem(100)));
	this->particleSystems.insert(std::make_pair("fx_destroy", new ParticleSystem(40)));
	this->particleSystems.insert(std::make_pair("fx_orb", new ParticleSystem(50)));
	this->particleSystems.insert(std::make_pair("fx_item", new ParticleSystem(50)));
	this->particleSystems["fx_tail"]->rateOverTime = false;
	this->particleSystems["fx_tail"]->setStartLifeTimeRange(1.0f,2.0f);
	this->particleSystems["fx_tail"]->setStartSpeedRange(0.02f,0.2f);
	this->particleSystems["fx_tail"]->setStartSizeRange(0.01f,0.02f);
	this->particleSystems["fx_tail"]->setStartAngleRange(0.0f,2.0f*PI);
	this->particleSystems["fx_tail"]->setGravity(0.0f);
	this->particleSystems["fx_tail"]->setColor(176,210,255,255);
	this->particleSystems["fx_destroy"]->setStartLifeTimeRange(0.1f,0.4f);
	this->particleSystems["fx_destroy"]->setStartSpeedRange(0.2f,1.0f);
	this->particleSystems["fx_destroy"]->setStartSizeRange(0.05f,0.1f);
	this->particleSystems["fx_destroy"]->setGravity(0.0f);
	this->particleSystems["fx_destroy"]->setColor(255,208,83,255);
	this->particleSystems["fx_orb"]->rate = 1;
	this->particleSystems["fx_orb"]->setStartLifeTimeRange(0.5f,1.0f);
	this->particleSystems["fx_orb"]->setStartSpeedRange(0.01f,0.2f);
	this->particleSystems["fx_orb"]->setStartSizeRange(0.02f,0.04f);
	this->particleSystems["fx_orb"]->setStartAngleRange(0.0f,2.0f*PI);
	this->particleSystems["fx_orb"]->setGravity(-0.05f);
	this->particleSystems["fx_orb"]->setColor(255,255,255,255);
	this->particleSystems["fx_item"]->setStartLifeTimeRange(0.5f,2.0f);
	this->particleSystems["fx_item"]->setStartSpeedRange(0.01f,0.2f);
	this->particleSystems["fx_item"]->setStartSizeRange(0.02f,0.04f);
	this->particleSystems["fx_item"]->setStartAngleRange(0.0f,2.0f*PI);
	this->particleSystems["fx_item"]->setGravity(-0.07f);
	this->particleSystems["fx_item"]->setColor(255,255,255,255);

	// start
	this->timer->start();
	this->resources->start();
	this->sceneManager->start();
}


/*------------------------------------------------------------------------------
< update >
------------------------------------------------------------------------------*/
void Game::update() {
	this->timer->update();
	this->sceneManager->update();
}


/*------------------------------------------------------------------------------
< get functions >
------------------------------------------------------------------------------*/
std::vector<GameObject*>* Game::getGameObjects() {
	return &this->gameObjects;
}
std::vector<BoxCollider*>* Game::getColliders() {
	return &this->colliders;
}
std::vector<GameObject*> Game::copyGameObjects() {
	return this->gameObjects;
}
std::vector<BoxCollider*> Game::copyColliders() {
	return this->colliders;
}

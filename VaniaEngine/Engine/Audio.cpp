
#include "Engine.hpp"

/*------------------------------------------------------------------------------
< Constructor >
------------------------------------------------------------------------------*/
Audio::Audio(const char* path) {
	this->path = path;
}


/*------------------------------------------------------------------------------
< Destructor >
------------------------------------------------------------------------------*/
Audio::~Audio() {
	
}


/*------------------------------------------------------------------------------
< Functions >
------------------------------------------------------------------------------*/
bool Audio::load() {

	return true;
}

void Audio::play() {
 getGame()->resources->iSoundEngine->play2D(this->path, this->loop);
}

bool Audio::playing() {
 if (getGame()->resources->iSoundEngine->isCurrentlyPlaying(this->path)) return true;
	return false;
}

void Audio::stop() {
	// DWORD status;
	// this->soundBuffer->GetStatus(&status);
	// if (status & DSBSTATUS_PLAYING ) this->soundBuffer->Stop();
}

void Audio::reset() {
	// this->soundBuffer->SetCurrentPosition(0);
}

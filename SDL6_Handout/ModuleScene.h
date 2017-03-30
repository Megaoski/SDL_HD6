

#ifndef _MODULESCENE_H
#define _MODULESCENE_H


#include "Module.h" 
#include "ModuleAudio.h"

struct SDL_Texture;

class ModuleScene : public Module
{
public:
	ModuleScene();
	~ModuleScene();

	bool Start();
	update_status Update();
	bool CleanUp();

public:

	SDL_Texture* intro = nullptr;
	Mix_Music* musiquita;
	
};

#endif
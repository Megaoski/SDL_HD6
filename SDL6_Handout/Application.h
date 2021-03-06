#ifndef __APPLICATION_H__
#define __APPLICATION_H__

#include "Globals.h"

#define NUM_MODULES 11

class ModuleWindow;
class ModuleInput;
class ModuleTextures;
class ModuleRender;
class ModuleParticles;
class ModuleAudio;
class ModuleScene;
class ModuleSceneSpace;
class ModulePlayer;
class ModuleCollision;
class ModuleFadeToBlack;
class Module;

// TODO 1: Create an intro scene with rtype/intro.png that then fades to ModuleSpaceScene

class Application
{
public:

	Module* modules[NUM_MODULES];
	ModuleWindow* window;
	ModuleRender* render;
	ModuleInput* input;
	ModuleTextures* textures;
	ModuleParticles* particles;
	ModuleAudio* audio;
	ModuleScene* intro;
	ModuleSceneSpace* scene_space;
	ModulePlayer* player;
	ModuleCollision* collision;
	ModuleFadeToBlack* fade;

public:

	Application();
	~Application();

	bool Init();
	update_status Update();
	bool CleanUp();

};

// Global var made extern for Application ---
extern Application* App;

#endif // __APPLICATION_H__
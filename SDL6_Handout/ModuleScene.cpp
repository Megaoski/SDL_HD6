#include "Globals.h"
#include "Application.h"
#include "ModuleTextures.h"
#include "ModuleRender.h"
#include "ModulePlayer.h"
#include "ModuleScene.h"
#include "ModuleInput.h"
#include "ModuleFadeToBlack.h"
#include "ModuleSceneSpace.h"




ModuleScene::ModuleScene()
{}

ModuleScene::~ModuleScene()
{}

// Load assets
bool ModuleScene::Start()
{
	LOG("Loading intro scene");

	
	intro = App->textures->Load("rtype/intro.png");
	musiquita = App->audio->LoadMusic("rtype/intro.ogg");

	App->intro->Enable();
	/*App->audio->PlayMusic(musiquita);*/
	

	return true;
}

// UnLoad assets
bool ModuleScene::CleanUp()
{
	LOG("Unloading intro scene");

	App->textures->Unload(intro);
	
	/*App->audio->StopMusic();*/

	App->intro->Disable();

	return true;
}

// Update: draw background
update_status ModuleScene::Update()
{
	

	// Draw everything --------------------------------------
	App->render->Blit(intro, 0, 0, NULL);

	if (App->input->keyboard[SDL_SCANCODE_SPACE] == KEY_DOWN)
	{
		App->fade->FadeToBlack(App->intro, App->scene_space, 0.8f);
	}
	

	return UPDATE_CONTINUE;
}
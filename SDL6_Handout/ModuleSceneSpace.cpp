#include "Globals.h"
#include "Application.h"
#include "ModuleTextures.h"
#include "ModuleRender.h"
#include "ModulePlayer.h"
#include "ModuleSceneSpace.h"
#include "ModuleFadeToBlack.h"
#include "ModuleInput.h"

// Reference at https://www.youtube.com/watch?v=OEhmUuehGOA

ModuleSceneSpace::ModuleSceneSpace()
{}

ModuleSceneSpace::~ModuleSceneSpace()
{}

// Load assets
bool ModuleSceneSpace::Start()
{
	LOG("Loading space scene");
	
	background = App->textures->Load("rtype/flores.png");
	musiquita = App->audio->LoadMusic("rtype/starting.wav");
	lasersito = App->audio->LoadSFX("rtype/laser.wav");

	App->scene_space->Enable();
	App->player->Enable();


	/*App->audio->PlayMusic(musiquita);*/
	
	
	return true;
}

// UnLoad assets
bool ModuleSceneSpace::CleanUp()
{
	LOG("Unloading space scene");

	App->textures->Unload(background);
	App->player->Disable();
	/*App->audio->StopMusic();*/
	App->scene_space->Disable();
	
	return true;
}

// Update: draw background
update_status ModuleSceneSpace::Update()
{
	// Move camera forward -----------------------------
	int scroll_speed = 5;

	/*App->player->position.x += 1;
	App->render->camera.x -= 3;*/
	

	// Draw everything --------------------------------------
	App->render->Blit(background, 0, 0, NULL);

	if (App->input->keyboard[SDL_SCANCODE_SPACE] == KEY_DOWN)
	{
		App->audio->PlaySFX(lasersito);
	}
	
	
	return UPDATE_CONTINUE;
}
#ifndef __ModulePlayer_H__
#define __ModulePlayer_H__

#include "Module.h"
#include "Animation.h"
#include "p2Point.h"
#include "ModuleCollision.h"

struct SDL_Texture;
struct Collider;
enum COLLIDER_TYPE;


class ModulePlayer : public Module
{
public:
	ModulePlayer();
	~ModulePlayer();

	bool Start();
	update_status Update();
	bool CleanUp();

public:

	SDL_Texture* graphics = nullptr;
	Animation* current_animation = nullptr;
	Animation idle;
	Animation up;
	Animation down;
	iPoint position;

private:

	struct player_struct {
		int player_world_x, player_y;
		Collider* player_collider = nullptr;
		int lives = 3;
		/*Animation animations[AN_MAX];
		SDL_Scancode inputs[PI_MAX];*/

		/*uint score = 0;
		bool godmode = false;*/

		

		
		/*uint sdl_respawn = 0;*/
		

	};
	player_struct players;
};

#endif
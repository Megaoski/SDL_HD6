#ifndef __ModuleRenderer_H__
#define __ModuleRenderer_H__

#include "Module.h"
#include "SDL\include\SDL_rect.h"
#include "p2Point.h"
#include "p2Queue.h"

struct SDL_Renderer;
struct SDL_Texture;

class ModuleRender : public Module
{
public:
	ModuleRender();
	~ModuleRender();

	bool Init();
	update_status PostUpdate();
	update_status Update();
	update_status PreUpdate();
	bool CleanUp();

	bool Blit(SDL_Texture* texture, int x, int y, SDL_Rect* section, float speed = 1.0f);
	bool DrawQuad(const SDL_Rect& rect, Uint8 r, Uint8 g, Uint8 b, Uint8 a, bool use_camera = true);

public:
	SDL_Renderer* renderer = nullptr;
	SDL_Rect camera;
	iPoint render_size;
private:

	struct Quad_Request {
		Uint8 r, g, b, a;
		SDL_Rect rect;

		Quad_Request(Uint8 _r, Uint8 _g, Uint8 _b, Uint8 _a, SDL_Rect _rect) :
			r(_r), g(_g), b(_b), a(_a), rect(_rect)
		{}
	};

	pQueue<Quad_Request> quads;
};

#endif //__ModuleRenderer_H__
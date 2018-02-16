#ifndef OBJECT
#define OBJECT

#include <SDL.h>
#include <string>
#include <iostream>
#include "Point.h"

SDL_Texture *loadTexture(SDL_Renderer *renderer, std::string path);

extern SDL_Renderer *gRenderer;
extern SDL_Texture *gTexture;

// This class holds object position and texture info
class Object {
public:
	Object(SDL_Renderer *renderer, std::string path, Point pos, Point texSize);

	Point m_pos; 
	Point m_texSize;

	SDL_Texture *m_texture = NULL;

	//SDL_Rect placementRect;
	void Render(SDL_Renderer *renderer);

	~Object();
};

#endif
#ifndef OBJECT
#define OBJECT

#include <SDL.h>
#include <string>
#include <iostream>
#include "Point.h"

// This class holds object position and texture info
class Object {
public:
	Object(SDL_Texture *texture, Point pos, Point texSize, double rotation);

	Point m_pos; 
	Point m_texSize;

	double m_rotation;

	SDL_Texture *m_texture = NULL;

	//SDL_Rect placementRect;
	void Render(SDL_Renderer *renderer);

	~Object();
};

#endif
#ifndef UIELEMENT
#define UIELEMENT

#include <SDL.h>
#include <string>
#include "Point.h"

SDL_Texture *loadTexture(SDL_Renderer *renderer, std::string path);

class UIElement {
public:
	UIElement(SDL_Renderer *renderer, std::string path, Point pos);

	virtual void update();  //pure virtual function

	Point m_position;  //position
	int m_texWidth, m_texHeight;

	SDL_Texture *m_texture = NULL;
	void render(SDL_Renderer *renderer);
};

#endif // !UIELEMENT


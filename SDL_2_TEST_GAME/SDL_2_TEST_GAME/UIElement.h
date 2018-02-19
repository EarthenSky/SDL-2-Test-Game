#ifndef UIELEMENT
#define UIELEMENT

#include <SDL.h>
#include <string>
#include <vector>
#include "Point.h"
#include "Object.h"

SDL_Texture *loadTexture(SDL_Renderer *renderer, std::string path);

class UIElement {
public:
	virtual void update();  //not a pure virtual function

	Point m_position;  //position of the UIElement (the object carrier)

	std::vector<Object> m_objList;  // Holds all of the texture objects

	void AddUIObject(SDL_Texture *texture, Point pos, Point texSize);
	void render(SDL_Renderer *renderer);



	SDL_Texture *m_texture = NULL;
};

#endif // !UIELEMENT


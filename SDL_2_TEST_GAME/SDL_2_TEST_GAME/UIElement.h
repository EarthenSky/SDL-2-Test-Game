#ifndef UIELEMENT
#define UIELEMENT

#include <SDL.h>
#include <string>
#include <list>
#include "Point.h"
#include "Object.h"

SDL_Texture *loadTexture(SDL_Renderer *renderer, std::string path);

class UIElement {
public:
	virtual void update();  //not a pure virtual function

	Point m_position;  //position of the UIElement (the object carrier)

	std::list<Object> m_objList;  // Holds all of the texture objects

	void AddUIObject(SDL_Renderer *renderer, std::string path, Point pos, Point texSize);

	void render(SDL_Renderer *renderer);
};

#endif // !UIELEMENT


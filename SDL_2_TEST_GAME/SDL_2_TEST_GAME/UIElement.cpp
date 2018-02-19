#include "UIElement.h"

// This function creates an object and adds it to a list
void UIElement::AddUIObject(SDL_Texture *texture, Point pos, Point texSize)
{
	m_texture = texture;

	printf("Create obj \n");
	// Adds an object to the list.
	Object object(texture, pos, texSize);
	m_objList.push_back(object);
}

// This function renders the child objects.s
void UIElement::render(SDL_Renderer *renderer)
{
	//printf("RENDERING \n");
	// Iterates over all childs objects and calls their render function.
	for (Object obj : m_objList) {
		//obj.Render(renderer);
		//printf("0");
	}

	SDL_Rect placementRect = { 50, 60, 300, 600 };
	SDL_RenderCopy(renderer, m_texture, NULL, &placementRect);
}

void UIElement::update()
{
	//Do nothing...
	printf("nasingu");
}
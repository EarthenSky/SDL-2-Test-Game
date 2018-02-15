#include "UIElement.h"

// This function creates an object and adds it to a list
void UIElement::AddUIObject(SDL_Renderer *renderer, std::string path, Point pos, Point texSize)
{
	// Adds an object to the list.
	Object object(renderer, path, pos, texSize);
	m_objList.push_back(object);
}

// This function renders the child objects.s
void UIElement::render(SDL_Renderer *renderer)
{
	// Iterates over all childs objects and calls their render function.
	for (Object obj : m_objList) {
		obj.Render(renderer);
	}
}

void UIElement::update()
{
	//Do nothing...
}
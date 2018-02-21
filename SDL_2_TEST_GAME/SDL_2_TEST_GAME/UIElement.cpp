#include "UIElement.h"

// This function creates an object and adds it to a list
void UIElement::AddUIObject(SDL_Texture *texture, Point pos, Point texSize)
{
	// Adds an object to the list.
	m_objList.push_back(new Object(texture, pos, texSize));
}

// This function renders the child objects.s
void UIElement::render(SDL_Renderer *renderer)
{ 
	// Iterates over all childs objects and calls their render function.
	for (Object* obj : m_objList) {
		obj->Render(renderer);
	}
}

void UIElement::update()
{
	//Do nothing...
	printf("nasingu");
}

UIElement::~UIElement() 
{
	//delete all object classes in the deconstructor to avoid memory leaks
	for (Object* obj : m_objList) {
		delete obj;
	}
}
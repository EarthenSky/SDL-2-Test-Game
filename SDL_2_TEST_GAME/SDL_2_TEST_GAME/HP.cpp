#include "HP.h"

void HPR::update()
{
	//maths
}

void HPR::render(SDL_Renderer *renderer)
{
	//This calls the inherited render function.  just in case... i think...
	UIElement::render(renderer);
}

void HPR::init(SDL_Renderer *renderer)
{
	// Bar Background Object
	std::string markerPath = "Images/HealthMarker.bmp";
	SDL_Texture *markerTex = loadTexture(renderer, markerPath);

	// Create the 5 health bar items.
	for (double index = 0; index < 5; index++) {
		UIElement::AddUIObject(markerTex, { (index * 75) + 25, 25}, { 50, 50 });
	}
}

void HPR::setHPSize(int newhpSize)
{
	//loop through all hp objects above a certain hp and make sure they are off
	for (int index = 5; index > newhpSize; index--) {
		//printf("%d", index);
		UIElement::m_objList.at(index - 1)->hidden = true;  //hide the hp texture object.
	}
}
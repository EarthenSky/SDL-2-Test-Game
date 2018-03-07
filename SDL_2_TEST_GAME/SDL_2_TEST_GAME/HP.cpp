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
	std::string backPath = "Images/HealthMarker.png";
	SDL_Texture *backTex = loadTexture(renderer, backPath);

	// Create the 5 health bar items.
	for (int index = 0; index < 5; index++) {
		UIElement::AddUIObject(backTex, { 25, (index * 50) + 25 }, { 100, 100 });
	}
}

void HPR::setHPSize(int newhpSize)
{
	//loop through all hp objects above a certain hp and make sure they are off
	for (int index = 5; index > newhpSize; index--) {
		UIElement::m_objList.at(index - 1)->hidden == true;  //hide the hp texture object.
	}
}
#include "WaveTimerBar.h"

void WaveTimerBar::update() 
{
	//do maths & timer stuff here
}

void WaveTimerBar::render(SDL_Renderer *renderer)
{
	//this calls the inherited render function.
	UIElement::render(renderer);
}

void WaveTimerBar::init(SDL_Renderer *renderer)
{
	// Bar Background Object
	std::string backPath = "Images/BarBack.bmp";
	SDL_Texture *backTex = loadTexture(renderer, backPath);

	UIElement::AddUIObject(backTex, { 200, 100 }, { 100, 400 });

	// Bar Fill Object (the moving colour part)
	//	TODO: bar fill obj

	// Bar Front Object
	std::string frontPath = "Images/BarFront.bmp";
	SDL_Texture *frontTex = loadTexture(renderer, frontPath);

	UIElement::AddUIObject(frontTex, { 200, 100 }, { 100, 400 });
}
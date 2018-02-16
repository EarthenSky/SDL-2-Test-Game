#include "WaveTimerBar.h"

void WaveTimerBar::update() 
{
	//do maths & timer stuff here
}

WaveTimerBar::WaveTimerBar(SDL_Renderer *renderer)
{
	// Bar Back
	std::string backPath = "Images/BarBack.bmp";
	UIElement::AddUIObject(renderer, backPath, { 200, 200 }, { 100, 100 });

	// Bar Front
	std::string frontPath = "Images/BarFront.bmp";
	UIElement::AddUIObject(renderer, frontPath, { 300, 200 }, { 100, 100 });
}
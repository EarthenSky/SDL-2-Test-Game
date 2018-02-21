#include "UI.h"
//class ha:
//renders and does ui maths for things like hp or points.
//not a class
//holds ui items

WaveTimerBar gUIWaveBar;

//Initialize UI Objects here
void initUI(SDL_Renderer *renderer)
{
	gUIWaveBar.init(renderer);
}

void updateUI()
{
	gUIWaveBar.update();
}

void renderUI(SDL_Renderer *renderer)
{
	gUIWaveBar.render(renderer);
}

void freeUI()
{

}

//list of Classes with IUiElement interfaces?
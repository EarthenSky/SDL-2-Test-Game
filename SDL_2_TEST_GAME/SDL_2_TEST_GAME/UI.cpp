#include "UI.h"
//class ha:
//renders and does ui maths for things like hp or points.
//not a class
//holds ui items

WaveTimerBar gUIWaveBar;
HPR gHP;

//Initialize UI Objects here
void initUI(SDL_Renderer *renderer)
{
	gUIWaveBar.init(renderer);
	gHP.init(renderer);
}

void updateUI()
{
	gUIWaveBar.update();
	gHP.update();
}

void renderUI(SDL_Renderer *renderer)
{
	gUIWaveBar.render(renderer);
	gHP.render(renderer);
}

void freeUI()
{
	//...nope?
}

//list of Classes with IUiElement interfaces?
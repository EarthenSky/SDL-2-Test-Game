#include "UI.h"
//class ha:
//renders and does ui maths for things like hp or points.
//not a class
//holds ui items

WaveTimerBar gUIWaveBar;
HPR gHP;
DashCharges gDashCharges;

//Initialize UI Objects here (create textures, etc.)
void initUI(SDL_Renderer *renderer)
{
	gUIWaveBar.init(renderer);
	gHP.init(renderer);
	gDashCharges.init(renderer);
}

// Do maths and calculations, etc.
void updateUI()
{
	gUIWaveBar.update();
	gHP.update();
	gDashCharges.update();
}

void renderUI(SDL_Renderer *renderer)
{
	gUIWaveBar.render(renderer);
	gHP.render(renderer);
	gDashCharges.render(renderer);
}

void freeUI()
{
	//...nope?
}
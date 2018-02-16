#include "UI.h"
//class ha:
//renders and does ui maths for things like hp or points.
//not a class
//holds ui items

std::list<UIElement> listUIElements;

//Initialize UI Objects here
void initUI(SDL_Renderer *renderer)
{
	WaveTimerBar uiWaveBar(renderer);
	listUIElements.push_back(uiWaveBar);
}

void updateUI()
{
	for (UIElement ui : listUIElements) {
		ui.update();
	}
}

void renderUI(SDL_Renderer *renderer)
{
	for (UIElement ui : listUIElements) {
		ui.render(renderer);
	}
}

void freeUI()
{

}

//list of Classes with IUiElement interfaces?


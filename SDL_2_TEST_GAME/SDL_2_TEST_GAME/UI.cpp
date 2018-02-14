#include "UI.h"
//class w/ha:
//renders and does ui maths for things like hp or points.
//not a class
//holds ui items

std::list<UIElement> listUIElements;

void addUIElement(UIElement &ui)
{
	listUIElements.push_back(ui);
}

void updateUI()
{
	for (UIElement ui : listUIElements) {
		ui.update();
	}
}

void renderUI() 
{

}

void freeUI()
{

}

//list of Classes with IUiElement interfaces?


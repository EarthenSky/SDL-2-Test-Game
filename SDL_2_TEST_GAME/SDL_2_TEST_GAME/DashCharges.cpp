#include "DashCharges.h"

float currentTimerValue2 = 0;
float initTime2 = 0;

int chargeCount = 0;

void DashCharges::addCharge() 
{
	// Increment chargeCount yet cap it at 3.
	chargeCount++; if (chargeCount > 3) chargeCount = 3;

	// Change the texture
	UIElement::m_objList.at(chargeCount - 1 + 3)->m_texture = m_chargeOnTex;
}

bool DashCharges::removeCharge()
{
	// Increment chargeCount yet cap it at 0.
	chargeCount--; if (chargeCount < 0) chargeCount = 0;

	// Change the texture
	UIElement::m_objList.at(chargeCount + 3)->m_texture = m_chargeOffTex;

	if (chargeCount == 0) {
		return false;
	}
	else {
		return true;
	}
}

void DashCharges::update()
{
	// Calculate time since start
	currentTimerValue2 = SDL_GetTicks() - initTime2;

	// Move the bar over time
	m_objList[1]->m_pos = { m_objList[1]->m_pos.x, (131 * 4 - currentTimerValue2 / 26.4 * 10/4) };
	m_objList[1]->m_texSize = { m_objList[1]->m_texSize.x, (currentTimerValue2 / 26.4 * 10/4) };

	// If timer reaches 10 seconds reset timer and add new charge
	if (currentTimerValue2 > 4 * 1000) {
		// Add new charge.
		DashCharges::addCharge();

		// Reset timer.
		initTime2 = SDL_GetTicks();
	}
}

void DashCharges::render(SDL_Renderer *renderer)
{
	//this calls the inherited render function.
	UIElement::render(renderer);
}

void DashCharges::init(SDL_Renderer *renderer)
{
	srand(time(NULL));  // Init the rng

	// Bar Background Object
	std::string backPath = "Images/BarBack.bmp";
	SDL_Texture *backTex = loadTexture(renderer, backPath);

	DashCharges::AddUIObject(backTex, { 150 + 800, 135 }, { 100, 400 });

	// Bar Fill Object (the moving colour part)
	std::string fillPath = "Images/Colour.bmp";
	SDL_Texture *fillTex = loadTexture(renderer, fillPath);

	DashCharges::AddUIObject(fillTex, { 150 + 800, 131 * 4 }, { 100, 5 }, 90);

	// Bar Front Object
	std::string frontPath = "Images/BarFront.bmp";
	SDL_Texture *frontTex = loadTexture(renderer, frontPath);

	DashCharges::AddUIObject(frontTex, { 150 + 800, 135 }, { 100, 400 });

	// Init Charge Textures
	std::string noChargePath = "Images/NoCharge.bmp";
	std::string redChargePath = "Images/RedCharge.bmp";

	m_chargeOffTex = loadTexture(renderer, noChargePath);
	m_chargeOnTex = loadTexture(renderer, redChargePath);

	// Create the 3 charge objects.
	for (double index = 0; index < 3; index++) {
		UIElement::AddUIObject(m_chargeOffTex, { 950 - (index * 70), 25 }, { 50, 50 });
	}

	// Sets the initial time modifier (ms).
	initTime2 = SDL_GetTicks();
}

//clean up after Dash Charges.
DashCharges::~DashCharges() 
{
	//Free loaded images
	SDL_DestroyTexture(m_chargeOnTex);
	m_chargeOnTex = NULL;

	SDL_DestroyTexture(m_chargeOffTex);
	m_chargeOffTex = NULL;
}
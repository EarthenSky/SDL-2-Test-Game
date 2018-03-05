#include "WaveTimerBar.h"

float currentTimerValue = 0;
float initTime = 0;

void WaveTimerBar::update() 
{
	// Calculate time since start
	currentTimerValue = SDL_GetTicks() - initTime;
	//printf("0");

	// Move the bar over time
	m_objList[1]->m_pos = { m_objList[1]->m_pos.x, (int)(131 * 4 - currentTimerValue / 26.4) };
	m_objList[1]->m_texSize = { m_objList[1]->m_texSize.x, (int)(currentTimerValue / 26.4) };

	// If time is 10 seconds reset timer
	if (currentTimerValue > 10 * 1000) {

		// TODO: Call spawn enemies.
		for (int i = 0; i < 2; i++) {
			gEnemyManager.spawnEnemy({ 600, i * 5 }, { 160, 160 });
		}
		

		initTime = SDL_GetTicks();
		//printf("1\n1\n1\n1\n1\n1\n1\n\n\n\n\n\n\n1\n1\n1");
	}
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

	UIElement::AddUIObject(backTex, { 150, 135 }, { 100, 400 });

	// Bar Fill Object (the moving colour part)
	std::string fillPath = "Images/Colour.bmp";
	SDL_Texture *fillTex = loadTexture(renderer, fillPath);

	UIElement::AddUIObject(fillTex, { 150, 131*4 }, { 100, 5 }, 90);

	// Bar Front Object
	std::string frontPath = "Images/BarFront.bmp";
	SDL_Texture *frontTex = loadTexture(renderer, frontPath);

	UIElement::AddUIObject(frontTex, { 150, 135 }, { 100, 400 });

	// Sets the initial time modifier (ms).
	initTime = SDL_GetTicks();
}
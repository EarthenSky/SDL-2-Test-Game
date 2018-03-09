#include "WaveTimerBar.h"

float currentTimerValue = 0;
float initTime = 0;

void WaveTimerBar::update() 
{
	// Calculate time since start
	currentTimerValue = SDL_GetTicks() - initTime;
	//printf("0");

	// Move the bar over time
	m_objList[1]->m_pos = { m_objList[1]->m_pos.x, (131 * 4 - currentTimerValue / 26.4) };
	m_objList[1]->m_texSize = { m_objList[1]->m_texSize.x, (currentTimerValue / 26.4) };

	// If timer reaches 10 seconds reset timer and spawn enemies
	if (currentTimerValue > 10 * 1000) {
		// Randomize enemy count
		int enemyCount = currentWave + (rand() % 5 - 2);
		if (enemyCount <= 0) enemyCount = 1;
		
		// Spawn enemies equal to enemy count
		for (int i = 0; i < enemyCount; i++) {
			int spawnAreaNum = rand() % 3; //0 - 4
			
			int ySpawnPos;

			// This keeps the enemy from spawning on the player, instead
			// the enemy spawns out of the arena and is pushed to the edge by collision.
			if (spawnAreaNum == 0) {  //this places the enemy to the left of the arena
				int xSpawnPos = rand() % 300;
			}
			else if (spawnAreaNum == 1) {  //this places the enemy to the right of the arena
				int xSpawnPos = rand() % 1400 + 900;
			}
			else {  //this places the enemy in the arena (over or below)
				int xSpawnPos = rand() % 900 + 300;
			}
			gEnemyManager.spawnEnemy({ 400, (double)i * 20 }, { 80, 80 });
		}
	
		initTime = SDL_GetTicks();

		currentWave++;
	}
}

void WaveTimerBar::render(SDL_Renderer *renderer)
{
	//this calls the inherited render function.
	UIElement::render(renderer);
}

void WaveTimerBar::init(SDL_Renderer *renderer)
{
	srand(time(NULL));  // Init the rng

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
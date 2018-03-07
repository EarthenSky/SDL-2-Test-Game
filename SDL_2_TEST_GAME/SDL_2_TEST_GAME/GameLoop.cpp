#include "GameLoop.h"

const int STOPPED = 0;
const int RUNNING = 1;
const int PAUSED = 2;
int gGameState = RUNNING;

SDL_Event gInputHandler;  // Event handler for input.

Player gPlayer;  // Holds player info.
Scene gScene;  // Holds scene info.
EnemyManager gEnemyManager;  // Holds all enemy info.

SDL_Texture *gTextureBarBack = NULL;

void gameLoopInit()
{
	// Init object classes here
	gPlayer.init(gRenderer, "Images/Char.bmp", {160, 160});
	gScene.init(gRenderer, "Images/Arena.bmp");
	gEnemyManager.init(gRenderer);  // This initializes the textures.
	
	initUI(gRenderer);  // Init all UI objects.

	updateLoop();
}  //Class destructors are called here

void updateLoop()
{
	// Main game loop
	while (gGameState != STOPPED) {
		if (gGameState == RUNNING) {
			updateUI();  // Update all ui functions

			// Updates player math and collision (collision function sent here.)
			gPlayer.update();
			gPlayer.collision(gScene.checkArenaCollision(gPlayer.m_position, gPlayer.m_texHeight / 2));

			gEnemyManager.update();  // Update all enemy classes

			renderAssets();  //renders textures.
		}
		else if (gGameState == PAUSED) {
			//menu code here
		}

		handleInput();  //also handles keyboard and mouse input.

		//debug code here
	}
}

void renderAssets()
{
	//clear screen
	SDL_RenderClear(gRenderer);

	// Call class render functions here (first rendered goes to the bottom-most layer)
	gScene.render(gRenderer);
	gEnemyManager.render(gRenderer);
	gPlayer.render(gRenderer);

	// Render the UI above all other assets
	renderUI(gRenderer);

	//update screen
	SDL_RenderPresent(gRenderer);
}

void handleInput()
{
	while (SDL_PollEvent(&gInputHandler) != 0) {
		if (gInputHandler.type == SDL_QUIT) {
			gGameState = STOPPED;
		}

		gPlayer.checkInput();
	}
}

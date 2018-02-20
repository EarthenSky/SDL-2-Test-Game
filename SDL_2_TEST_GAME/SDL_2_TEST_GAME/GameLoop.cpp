#include "GameLoop.h"

const int STOPPED = 0;
const int RUNNING = 1;
const int PAUSED = 2;
int gGameState = RUNNING;

SDL_Event gInputHandler;  // Event handler for input.

Player gPlayer;  // Holds player info.
Scene gScene;  // Holds scene info.

SDL_Texture *gTextureBarBack = NULL;

void gameLoopInit()
{
	// Init object classes here
	gPlayer.init(gRenderer, "Images/Char.bmp", {160, 160});
	gScene.init(gRenderer, "Images/Arena.bmp");

	//init global textures
	gTextureBarBack = loadTexture(gRenderer, "Images/BarBack.bmp");

	initUI(gRenderer);  // Init all UI objects.

	updateLoop();
}  //Class destructors are called here

void updateLoop()
{
	//main game loop
	while (gGameState != STOPPED) {
		if (gGameState == RUNNING) {
			updateUI();  //Update all ui functions

			//regular game code goes here
			
			//updates player math and collision (collision function sent here.)
			gPlayer.update();
			gPlayer.collision(gScene.checkArenaCollision(gPlayer.m_position, gPlayer.m_texHeight / 2));

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

	//render stuff here (first rendered goes to the bottom)
	gScene.render(gRenderer);
	//enemy manager render call here
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

#include "GameLoop.h"

const int STOPPED = 0;
const int RUNNING = 1;
const int PAUSED = 2;
int gGameState = RUNNING;

SDL_Event gInputHandler;  //Event handler for input

Player gPlayer;  //holds player info
Scene gScene;  //holds scene info

void gameLoopInit()
{
	//init classes here
	gPlayer.init(gRenderer, "Images/Char.bmp", {160, 160});
	gScene.init(gRenderer, "Images/Arena.bmp");

	update();
	closeMedia();  //this is called when game is closed
}

void update()
{
	//main game loop
	while (gGameState != STOPPED) {
		if (gGameState == RUNNING) {
			
			//regular game code here
			
			//updates player math and collision (collision function sent here.)
			gPlayer.update();
			gPlayer.collision(gScene.checkArenaCollision(gPlayer.position, gPlayer.texHeight / 2));

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
	gPlayer.render(gRenderer);

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

//free textures and other media
void closeMedia()
{
	gPlayer.freeAssets();
	gScene.freeAssets();
}

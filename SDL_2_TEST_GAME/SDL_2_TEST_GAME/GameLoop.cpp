#include "GameLoop.h"

const int STOPPED = 0;
const int RUNNING = 1;
const int PAUSED = 2;
int gGameState = RUNNING;

SDL_Event gInputHandler;  //Event handler for input

Player gPlayer;  //holds player info

void gameLoopInit()
{
	//init classes here
	gPlayer.init(gRenderer, "Char.bmp", 160, 160);

	update();
	closeMedia();  //this is called when game is closed
}

void update()
{
	//main game loop
	while (gGameState != STOPPED) {
		if (gGameState == RUNNING) {
			renderAssets();  //renders textures.

			gPlayer.update();  //updates player math

			//regular game code here
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

	//render stuff here
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

}

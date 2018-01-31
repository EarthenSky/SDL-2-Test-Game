#include "GameLoop.h"

SDL_Event gInputHandler;  //handles different types of input

const int STOPPED = 0;
const int RUNNING = 1;
const int PAUSED = 2;
int gGameState = RUNNING;

void startGameLoop()
{
	update();
}

void update()
{
	//main GameLoop:
	while (gGameState != STOPPED) {
		if (gGameState == RUNNING) {
			renderAssets();  //renders textures.

			//regular game code here
		}
		else if (gGameState == PAUSED) {
			//menu code here
		}

		handleInput();  //also handles keyboard and mouse input.

		//debug code here
	}

	closeMedia();
}

void renderAssets()
{
	//clear screen
	SDL_RenderClear(gRenderer);

	//render stuff here

	//update screen
	SDL_RenderPresent(gRenderer);
}

void handleInput()
{
	while (SDL_PollEvent(&gInputHandler) != 0) {
		if (gInputHandler.type == SDL_QUIT) {
			gGameState = STOPPED;
		}
	}
}

//free textures and other media
void closeMedia()
{

}

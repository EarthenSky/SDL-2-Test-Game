#include <SDL.h>
#include <stdio.h>

void RenderAssets(SDL_Renderer *renderer);
void HandleInput();
void closeMedia();

SDL_Event gInputHandler;  //handles different types of input

const int STOPPED = 0;
const int RUNNING = 1;
const int PAUSED = 2;
int gGameState = RUNNING;

//SDL_Renderer *gRenderer = NULL;  //not og gRenderer
//have a start game loop function and an update function

void GameLoop(SDL_Renderer *renderer)
{
	//main GameLoop:
	while (gGameState != STOPPED) {
		if (gGameState == RUNNING) {
			RenderAssets(renderer);  //renders textures.

			//regular game code here
		}
		else if (gGameState == PAUSED) {
			//menu code here
		}

		HandleInput();  //also handles keyboard and mouse input.

		//debug code here
	}

	closeMedia();
}

void RenderAssets(SDL_Renderer *renderer)
{
	//clear screen
	SDL_RenderClear(renderer);

	//render stuff here

	//update screen
	SDL_RenderPresent(renderer);
}

void HandleInput()
{
	while (SDL_PollEvent(&gInputHandler) != 0) {
		if (gInputHandler.type == SDL_QUIT) {
			//i put (==) here instead of (=).  Litteraly the first time i've done this...
			gGameState = STOPPED;
		}
	}
}

//free textures and other media
void closeMedia()
{

}

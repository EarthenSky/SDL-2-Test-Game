#include "GameManager.h"

const int SCREEN_HEIGHT = 600;
const int SCREEN_WIDTH = 600;

SDL_Window *gWindow = NULL;  //null pointer is better than garbage pointer
SDL_Renderer *gRenderer = NULL;  //NULL = 0 in most compilers

int main(int argc, char* args[]) 
{
	printf("staatou! \n");

	SDL_Init(SDL_INIT_VIDEO);

	gWindow = SDL_CreateWindow(
		"This is the name of the Window", 
		SDL_WINDOWPOS_UNDEFINED, 
		SDL_WINDOWPOS_UNDEFINED, 
		SCREEN_WIDTH, 
		SCREEN_HEIGHT, 
		SDL_WINDOW_SHOWN
	);

	//vsync is on therefore psudeo infinite loops will run at around 60fps.
	gRenderer = SDL_CreateRenderer(
		gWindow, 
		-1, 
		SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC
	);

	SDL_SetRenderDrawColor(gRenderer, 0, 24, 78, 0);  //sets the render color to white.

	startGameLoop();  //starts the main loop

	finalClose();
	return 0;
}

void finalClose() 
{
	//Destroy renderer
	SDL_DestroyRenderer(gRenderer);
	gRenderer = NULL;

	//Destroy window
	SDL_DestroyWindow(gWindow);
	gWindow = NULL;

	SDL_Quit();

}
#include <SDL.h>
//#include <stdio.h>

class Player {
	int xPos, yPos;  //position
	int xVel, yVel;  //velocity
	SDL_Texture tex;

	void init();
};
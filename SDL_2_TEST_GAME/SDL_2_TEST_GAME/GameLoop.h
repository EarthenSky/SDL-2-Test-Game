#ifndef GAMELOOP
#define GAMELOOP

#include <SDL.h>
#include <stdio.h>

extern SDL_Renderer *gRenderer;

void update();
void renderAssets();
void handleInput();
void closeMedia();

#include "Player.h"

#endif 

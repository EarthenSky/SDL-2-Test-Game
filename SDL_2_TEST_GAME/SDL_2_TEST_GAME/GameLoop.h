#ifndef GAMELOOP
#define GAMELOOP

#include <SDL.h>
#include <stdio.h>

extern SDL_Renderer *gRenderer;

void update();
void renderAssets();
void handleInput();

#include "Player.h"
#include "Scene.h"
#include "UI.h" //I think

#endif 

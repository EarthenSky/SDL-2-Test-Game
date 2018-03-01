#ifndef GAMELOOP
#define GAMELOOP

#include <SDL.h>
#include <stdio.h>

extern SDL_Renderer *gRenderer;

void updateLoop();
void renderAssets();
void handleInput();

#include "Player.h"
#include "Scene.h"
#include "EnemyManager.h"
#include "UI.h" //I think

#endif 

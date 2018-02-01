#include "Player.h"


void Player::init(SDL_Renderer *renderer, std::string path, int xPosition, int yPosition) {
	xPos = xPosition;
	yPos = yPosition;
	texture = loadTexture(renderer, path);
}

void Player::freeAssets()
{
	//Free loaded image
	SDL_DestroyTexture(texture);
	texture = NULL;
}

void Player::update()
{
	//move player based on velocity
	xPos += xVel;
	yPos += yVel;
}

void Player::render(SDL_Renderer *renderer) 
{
	//cuts out a single pane of the player animation and sets it to the players position.
	SDL_Rect playerRect = { xPos, yPos, 400, 400 };
	//SDL_Rect cutRect = { 0, 16, 16, 16 };

	SDL_RenderCopy(renderer, texture, NULL, &playerRect);
}

/*Movement Code Under*/

//TODO: if two keys are pressed just have it stop
//is key down?
bool wKeyDown = false;
bool aKeyDown = false;
bool sKeyDown = false;
bool dKeyDown = false;

//how many movement keys are down.
int keySum()
{
	return wKeyDown + aKeyDown + sKeyDown + dKeyDown;
}

//makes the key that is down activate the movement.
void pressedKeyMoves(int &xVelocity, int &yVelocity)
{
	if (wKeyDown == true) { 
		xVelocity = 0;
		yVelocity = -8;
	}
	else if (aKeyDown == true) { 
		xVelocity = -8;
		yVelocity = 0;
	}
	else if (sKeyDown == true) { 
		xVelocity = 0;
		yVelocity = 8;
	}
	else if (dKeyDown == true) { 
		xVelocity = 8;
		yVelocity = 0;
	}
}

//inputHandler is a reference because it is faster than copying the value
void Player::checkInput()
{
	if (gInputHandler.type == SDL_KEYDOWN) {
		if (gInputHandler.key.keysym.sym == SDLK_w) {
			xVel = 0;
			yVel = -8;
			wKeyDown = true;
		}
		else if (gInputHandler.key.keysym.sym == SDLK_a) {
			xVel = -8;
			yVel = 0;
			aKeyDown = true;
		}
		else if (gInputHandler.key.keysym.sym == SDLK_s) {
			xVel = 0;
			yVel = 8;
			sKeyDown = true;
		}
		else if (gInputHandler.key.keysym.sym == SDLK_d) {
			xVel = 8;
			yVel = 0;
			dKeyDown = true;
		}
	}
	else if (gInputHandler.type == SDL_KEYUP) {
		if (gInputHandler.key.keysym.sym == SDLK_w) {
			wKeyDown = false;
			if (keySum() == 0) {
				xVel = 0;
				yVel = 0;
			}
			else {
				pressedKeyMoves(xVel, yVel);
			}
		}
		else if (gInputHandler.key.keysym.sym == SDLK_a) {
			aKeyDown = false;
			if (keySum() == 0) {
				xVel = 0;
				yVel = 0;
			}
			else {
				pressedKeyMoves(xVel, yVel);
			}
		}
		else if (gInputHandler.key.keysym.sym == SDLK_s) {
			sKeyDown = false;
			if (keySum() == 0) {
				xVel = 0;
				yVel = 0;
			}
			else {
				pressedKeyMoves(xVel, yVel);
			}
		}
		else if (gInputHandler.key.keysym.sym == SDLK_d) {
			dKeyDown = false;
			if (keySum() == 0) {
				xVel = 0;
				yVel = 0;
			}
			else {
				pressedKeyMoves(xVel, yVel);
			}
		}
	}
}

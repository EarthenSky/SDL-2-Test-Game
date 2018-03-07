#ifndef PLAYER
#define PLAYER

#include <SDL.h>
#include <string>
#include <cmath>
#include "Point.h"

//TODO: add player attacks to checkInput().

SDL_Texture *loadTexture(SDL_Renderer *renderer, std::string path);

extern SDL_Event gInputHandler;
extern int gGameState;

class Player {
public:
	void decrementHP();

	Point m_position;  //position
	Point m_velocity;  //velocity
	double m_rotation = 0;

	bool attackOn = false;

	int m_radius;

	int m_texWidth, m_texHeight;
	SDL_Texture *m_texture = NULL;

	void init(SDL_Renderer *renderer, std::string path, Point pos);

	//for physics things.  //TODO: framerate independence.
	void update();
	void Player::collision(Point collsionOffset);

	void render(SDL_Renderer *renderer);
	void checkInput();  //this is a reference

	~Player();

private:
	int hp = 5;
};

#endif
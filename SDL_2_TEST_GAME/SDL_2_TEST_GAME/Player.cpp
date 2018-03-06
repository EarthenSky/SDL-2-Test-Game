#include "Player.h"

void Player::init(SDL_Renderer *renderer, std::string path, Point pos) {
	m_position = pos;
	m_texture = loadTexture(renderer, path);
	m_texWidth = 80;
	m_texHeight = 80;
	m_radius = m_texWidth / 2;
}

int mousePosX = 0;
int mousePosY = 0;
double findPlayerAngle(int yPos, int xPos) 
{
	double angle1 = std::atan2(20000 - yPos, 0);
	double angle2 = std::atan2(mousePosY - yPos, mousePosX - xPos);
	//printf("", (angle1 - angle2) * 180 / 3.141592, "|||");
	return -((angle1 - angle2) * 180 / 3.141592) + 180;
}

// Player is moves by velocity then checks collision.
void Player::update()
{
	//move player based on velocity
	m_position.x += m_velocity.x;
	m_position.y += m_velocity.y;
}

void Player::collision(Point collsionOffset)
{
	// This moves this object based on the collision offset. 
	m_position.x -= collsionOffset.x;
	m_position.y -= collsionOffset.y;
}

void Player::render(SDL_Renderer *renderer) 
{
	//cuts out a single pane of the player animation and sets it to the players position.
	SDL_Rect placementRect = { m_position.x, m_position.y, m_texWidth, m_texHeight };
	//SDL_Rect cutRect = { 0, 16, 16, 16 };

	//find rotation just before setting rotation
	m_rotation = findPlayerAngle(m_position.y + m_texHeight / 2, m_position.x + m_texWidth / 2);

	SDL_RenderCopyEx(renderer, m_texture, NULL, &placementRect, m_rotation, NULL, SDL_FLIP_NONE);
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
void pressedKeyMoves(double &xVelocity, double &yVelocity)
{
	if (keySum() == 1) {
		if (wKeyDown == true) {
			xVelocity = 0;
			yVelocity = -4;
		}
		else if (aKeyDown == true) {
			xVelocity = -4;
			yVelocity = 0;
		}
		else if (sKeyDown == true) {
			xVelocity = 0;
			yVelocity = 4;
		}
		else if (dKeyDown == true) {
			xVelocity = 4;
			yVelocity = 0;
		}
	}
}

//inputHandler is a reference because it is faster than copying the value
void Player::checkInput()
{
	if (gInputHandler.type == SDL_KEYUP) {
		if (gInputHandler.key.keysym.sym == SDLK_w) {
			wKeyDown = false;
			if (keySum() == 0) {
				m_velocity.x = 0;
				m_velocity.y = 0;
			}
			else {
				pressedKeyMoves(m_velocity.x, m_velocity.y);
			}
		}
		else if (gInputHandler.key.keysym.sym == SDLK_a) {
			aKeyDown = false;
			if (keySum() == 0) {
				m_velocity.x = 0;
				m_velocity.y = 0;
			}
			else {
				pressedKeyMoves(m_velocity.x, m_velocity.y);
			}
		}
		else if (gInputHandler.key.keysym.sym == SDLK_s) {
			sKeyDown = false;
			if (keySum() == 0) {
				m_velocity.x = 0;
				m_velocity.y = 0;
			}
			else {
				pressedKeyMoves(m_velocity.x, m_velocity.y);
			}
		}
		else if (gInputHandler.key.keysym.sym == SDLK_d) {
			dKeyDown = false;
			if (keySum() == 0) {
				m_velocity.x = 0;
				m_velocity.y = 0;
			}
			else {
				pressedKeyMoves(m_velocity.x, m_velocity.y);
			}
		}
	}
	else if (gInputHandler.type == SDL_KEYDOWN) {
		if (gInputHandler.key.keysym.sym == SDLK_w) {
			m_velocity.x = 0;
			m_velocity.y = -4;
			wKeyDown = true;
		}
		else if (gInputHandler.key.keysym.sym == SDLK_a) {
			m_velocity.x = -4;
			m_velocity.y = 0;
			aKeyDown = true;
		}
		else if (gInputHandler.key.keysym.sym == SDLK_s) {
			m_velocity.x = 0;
			m_velocity.y = 4;
			sKeyDown = true;
		}
		else if (gInputHandler.key.keysym.sym == SDLK_d) {
			m_velocity.x = 4;
			m_velocity.y = 0;
			dKeyDown = true;
		}
	}
	else if (gInputHandler.type == SDL_MOUSEMOTION) {
		mousePosX = gInputHandler.motion.x;
		mousePosY = gInputHandler.motion.y;
	}
}

//cleans up after the class
Player::~Player() 
{
	//Free loaded image
	SDL_DestroyTexture(m_texture);
	m_texture = NULL;
}

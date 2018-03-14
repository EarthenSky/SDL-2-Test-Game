#ifndef DASHCHARGES
#define DASHCHARGES

#include "UIElement.h"
#include <stdlib.h>  // For rand()
#include <time.h>  // For time()

class DashCharges : public UIElement {
public:
	//the textures for both charges
	SDL_Texture *m_chargeOnTex = NULL;
	SDL_Texture *m_chargeOffTex = NULL;

	void addCharge();
	bool removeCharge();
	
	// The render objects are created here.
	void init(SDL_Renderer *renderer);

	virtual void update();  //This is the math function

	void render(SDL_Renderer *renderer);  //This is the math function

	~DashCharges();
};

#endif
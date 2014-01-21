/*
 * Player.h
 *
 *  Created on: 20 Jan 2014
 *      Author: Robin
 */

#ifndef PLAYER_H_
#define PLAYER_H_

// C++ Includes

// SDL Includes
#include "SDL2/SDL.h"

// Map Includes
#include "utils/MapTextures.h"

class Player {
public:
	Player(utils::MapTexture* playerIcon);
	virtual ~Player();

	void render();

	void move(int x, int y);

	int x = 5;
	int y = 5;

	int scale = 20;
private:
	utils::MapTexture* playerIcon;
};

#endif /* PLAYER_H_ */

/*
 * Tile.h
 *
 *  Created on: 16 Nov 2013
 *      Author: Robin
 */

#ifndef TILE_H_
#define TILE_H_

// SDL Includes
#include <SDL2/SDL.h>

// Map Includes
#include "utils/MapTextures.h"
#include "utils/logger.h"
#include "Entity.h"

/**
 * Class to store information about a tile on the map
 */

namespace core {

class Tile :public Entity {
public:

	//! Constructor
	Tile(int x, int y, utils::Texture* texture);
	virtual ~Tile();

	void setRotation(double rotation);

	//! Rotation of tile
	double rotation = 0.0;
	//! Tiles x location
	int x;
	//! Tiles y location
	int y;
	//! Tiles texture
	utils::Texture* texture = NULL;

};

}

#endif /* TILE_H_ */

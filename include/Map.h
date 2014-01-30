/*
 * Map.h
 *
 *  Created on: 20 Jan 2014
 *      Author: Robin
 */

#ifndef MAP_H_
#define MAP_H_

// C++ Includes
#include "Map"

// SDL Includes
#include "SDL2/SDL.h"

// Map Includes
#include "core/Tile.h"

namespace map {

class Map {
public:
	Map(int x, int y, int h, int w, SDL_Renderer* renderer);
	virtual ~Map();
	void setMap(std::vector<core::Tile*> map);
	void render();
	bool canMove(int x, int y);

private:
	std::map<SDL_Rect*, utils::Texture*> gameMap;

	std::vector<core::Tile*> tiles;
	SDL_Rect* viewSize = new SDL_Rect();
	SDL_Rect* viewArea = new SDL_Rect();

	int scale = 20;

	SDL_Renderer* renderer;
};

} /* namespace map */
#endif /* MAP_H_ */

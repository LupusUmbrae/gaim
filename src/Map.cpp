/*
 * Map.cpp
 *
 *  Created on: 20 Jan 2014
 *      Author: Robin
 */

#include "Map.h"

namespace map {

Map::Map(int x, int y, int h, int w, SDL_Renderer* renderer) {
	this->renderer = renderer;
	viewSize->x = x;
	viewSize->y = y;
	viewSize->h = h;
	viewSize->w = w;
}

Map::~Map() {
	// TODO Auto-generated destructor stub
}

void Map::setMap(std::vector<core::Tile*> map) {
	this->tiles.clear();

	this->gameMap.clear();

	SDL_Rect* loc;
	for (core::Tile* curTile : map) {
		loc = new SDL_Rect();
		loc->x = curTile->x;
		loc->y = curTile->y;
		loc->h = 0;
		loc->w = 0;

		this->gameMap.insert(std::make_pair(loc, curTile->texture));
	}

	this->tiles.insert(this->tiles.end(), map.begin(), map.end());

	map.clear();
}

void Map::render() {
	int x;
	int y;
	for (core::Tile *curTile : tiles) {
		x = (curTile->x * scale);
		y = (curTile->y * scale);

		if ((x >= (viewArea->x * scale)
				&& x < ((viewArea->x * scale) + viewSize->w))
				&& (y >= (viewArea->y * scale)
						&& y < ((viewArea->y * scale) + viewSize->h))) {

			// Correct locations within the actual screen
			x += viewSize->x - (viewArea->x * scale);
			y += viewSize->y - (viewArea->y * scale);
			curTile->texture->render(x, y, scale, scale);
		}
	}
}

bool Map::canMove(int x, int y) {

	SDL_Rect loc;
	loc.x = x;
	loc.y = y;
	loc.h = 0;
	loc.w = 0;

	SDL_Rect* curLoc = NULL;

	for (auto itemIter = gameMap.begin(); itemIter != gameMap.end();
			++itemIter) {
		curLoc = itemIter->first;
		if (loc.x == curLoc->x && loc.y == curLoc->y) {
			return true;
		}

	}

	return false;
}

}
/* namespace map */

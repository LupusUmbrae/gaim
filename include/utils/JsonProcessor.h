/*
 * JsonProcessor.h
 *
 *  Created on: 30 Dec 2013
 *      Author: Robin
 */

#ifndef JSONPROCESSOR_H_
#define JSONPROCESSOR_H_

// C++ Includes
#include <string>
#include <vector>
#include <fstream>
#include <sstream>
#include <dirent.h>

#include <json/json.h>

// SDL Includes
#include <SDL2/SDL.h>

// Map Includes
#include "../core/Tile.h"
#include "textures/Image.h"
#include "textures/Text.h"

namespace utils {

class JsonProcessor {
public:
	//! Constructor
	/*!
	 *
	 * @param renderer Global renderer
	 */
	JsonProcessor(SDL_Renderer* renderer);
	virtual ~JsonProcessor();

	//! Load the tilesets from json files
	/*!
	 * Searches the given directory for sub-folders containing json files and then attempts to load the tileset
	 * @param rootDir tileset root directory
	 * @return Vectory of loaded tilesets
	 */
	void loadTilesets(std::string rootDir);

	//! Load map from given json
	/*!
	 *
	 * @param saveFile File to load
	 * @return vector of the loaded tiles based on the json file
	 */
	std::vector<core::Tile*> loadMap(std::string saveFile);

	int getMapWidth() {
		return this->mapWidth;
	}
	int getMapHeight() {
		return this->mapHeight;
	}

	//! Save map to json
	/*!
	 *
	 * @param map vector of tiles of the current map
	 * @return styles json string of the map
	 */
	std::string saveMap(std::vector<core::Tile*>* map, int width, int height);

private:
	SDL_Renderer* renderer;

	int mapWidth;
	int mapHeight;

};

} /* namespace menu */
#endif /* JSONPROCESSOR_H_ */

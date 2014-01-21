/*
 * Gaim.h
 *
 *  Created on: 20 Jan 2014
 *      Author: Robin
 */

#ifndef GAIM_H_
#define GAIM_H_

// C++ Includes
#include <string>
#include <iostream>
#include <ostream>
#include <vector>
#include <fstream>

#include <dirent.h>

#include <json/json.h>

#include <sstream>

// SDL Includes
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_ttf.h>

// Map Includes
#include "utils/logger.h"
#include "utils/JsonProcessor.h"
#include "Map.h"
#include "utils/MapTextures.h"
#include "utils/textures/Image.h"
#include "Player.h"

const int SCREEN_WIDTH = 648;
const int SCREEN_HEIGHT = 480;
const int SCREEN_BPP = 32;

class Gaim {
public:
	Gaim();
	virtual ~Gaim();

	bool init();

	bool loadResources();

	//! This is the entry to the run loop for SDL
	void run();

	//! Called after SDL_Quit, attempts to unload all resources
	void cleanUp();

	//! Processes SDL Events.
	/*!
	 * This method either sends the event to the correct display::IDisplay, or processes them itself
	 * @param event The event to process
	 */
	void handleEvent(SDL_Event event);

private:

	map::Map* map;
	Player* player;

	SDL_Window *screen = NULL;
	SDL_Renderer *renderer = NULL;

	TTF_Font* font;

	utils::JsonProcessor* jsonProcessor;
};

#endif /* GAIM_H_ */

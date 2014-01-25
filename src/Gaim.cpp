/*
 * Gaim.cpp
 *
 *  Created on: 20 Jan 2014
 *      Author: Robin
 */

#include "Gaim.h"

Gaim::Gaim() {
	// TODO Auto-generated constructor stub

}

Gaim::~Gaim() {
	// TODO Auto-generated destructor stub
}

bool Gaim::init() {

	if (SDL_Init(SDL_INIT_EVERYTHING) == -1) {
		std::cout << "SDL_Init Error: " << SDL_GetError() << std::endl;
		return false;
	}

	int imgFlags = IMG_INIT_PNG;
	if (!(IMG_Init(imgFlags) & imgFlags)) {
		std::cout << "IMG_Init Error: " << IMG_GetError() << std::endl;
		return false;
	}

	if (TTF_Init() == -1) {
		std::cout << "TTF_Init Error: " << TTF_GetError() << std::endl;
		return false;
	}

	screen = SDL_CreateWindow("My game", SDL_WINDOWPOS_UNDEFINED,
			SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT,
			SDL_WINDOW_RESIZABLE);

	renderer = SDL_CreateRenderer(screen, -1, 0);

	if (renderer == NULL) {
		logSDLError(std::cout, "Create renderer failed");
	}

	SDL_SetWindowFullscreen(screen, 0);

	SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
	SDL_RenderClear(renderer);
	SDL_RenderPresent(renderer);

	if (screen == NULL) {
		return false;
	}

	return true;
}

bool Gaim::loadResources() {
	font = TTF_OpenFont("resources/verdana.ttf", 10);
	if (font == NULL) {
		std::cout << "TTF_OpenFont Error: " << TTF_GetError() << std::endl;
		return false;
	}

	jsonProcessor = new utils::JsonProcessor(renderer);
	jsonProcessor->loadTilesets("resources/tilesets/");

	std::vector<core::Tile*> loadedMap = jsonProcessor->loadMap(
			"resources/save.json");

	map = new map::Map(0, 0, SCREEN_HEIGHT, SCREEN_WIDTH, renderer);

	map->setMap(loadedMap);

	utils::Image* playerIcon = new utils::Image(renderer);
	playerIcon->loadImage("resources/player.png");

	player = new Player(playerIcon);

	return true;
}

void Gaim::run() {
	bool quit = false;
	SDL_Event event;

	while (quit == false) {
		SDL_RenderClear(renderer);

		while (SDL_PollEvent(&event)) {
			this->handleEvent(event);
			if (event.type == SDL_QUIT) {
				quit = true;
			}
		}

		map->render();
		player->render();

		SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
		SDL_RenderPresent(renderer);
	}

}

void Gaim::handleEvent(SDL_Event event) {
	if (event.type == SDL_KEYDOWN) {
		switch (event.key.keysym.sym) {
		case SDLK_UP:
			if (this->map->canMove(player->x, player->y - 1)) {
				player->move(0, -1);
			}
			break;
		case SDLK_DOWN:
			if (this->map->canMove(player->x, player->y + 1)) {
				player->move(0, 1);
			}
			break;
		case SDLK_LEFT:
			if (this->map->canMove(player->x - 1, player->y)) {
				player->move(-1, 0);
			}
			break;
		case SDLK_RIGHT:
			if (this->map->canMove(player->x + 1, player->y)) {
				player->move(1, 0);
			}
			break;
		}

	}
}

void Gaim::cleanUp() {
	for (utils::MapTexture* curTex : utils::MapTexture::loadedTextures) {
		curTex->~MapTexture();
		delete curTex;
	}

	SDL_DestroyRenderer(renderer);
	SDL_DestroyWindow(screen);
	SDL_Quit();
}

int main(int argc, char* args[]) {
	Gaim gaim;

	if (!gaim.init()) {
		return -1;
	}

	if (!gaim.loadResources()) {
		return -1;
	}

	gaim.run();

	return 0;
}

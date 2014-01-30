/*
 * MapTextures.cpp
 *
 *  Created on: 30 Nov 2013
 *      Author: Robin
 */

#include "utils/Texture.h"

namespace utils {

std::vector<Texture*> Texture::loadedTextures = { };

Texture::Texture() {
	width = 0;
	height = 0;
}

Texture::~Texture() {
	SDL_DestroyTexture(texture);
}

void Texture::render(int xPos, int yPos, int width, int height,
		SDL_Rect* clip, double angle, SDL_Point* center,
		SDL_RendererFlip flip) {
	//Set rendering space and render to screen
	SDL_Rect renderQuad = { xPos, yPos, this->width, this->height };

	if (width > 0) {
		renderQuad.w = width;
	}

	if (height > 0) {
		renderQuad.h = height;
	}

	//Set clip rendering dimensions
	if (clip != NULL) {
		renderQuad.w = clip->w;
		renderQuad.h = clip->h;
	}

	//Render to screen
	SDL_RenderCopyEx(renderer, texture, clip, &renderQuad, angle, center, flip);
}

void Texture::setAlpha(Uint8 alpha) {
	SDL_SetTextureAlphaMod(texture, alpha);
}

bool Texture::convertSurface(SDL_Surface* surface) {
	bool success = true;

	// Release the texture if one already exists
	if (texture != NULL) {
		SDL_DestroyTexture(texture);
	}

	if (surface != NULL) {

		texture = SDL_CreateTextureFromSurface(renderer, surface);
		if (texture == NULL) {
			logSDLError(std::cerr, "CreateTextureFromSurface");
			success = false;
		}

		width = surface->w;
		height = surface->h;

		SDL_FreeSurface(surface);

		Texture::loadedTextures.push_back(this);
	} else {
		logSDLError(std::cerr, "Surface was null");
		success = false;
	}
	return success;
}

int Texture::getHeight() {
	return this->height;
}

int Texture::getWidth() {
	return this->width;
}

void Texture::setUniqueName(std::string uniqueName) {
	this->uniqueName = uniqueName;
}

std::string* Texture::getUniqueName() {
	return &this->uniqueName;
}

void Texture::unload() {
	SDL_DestroyTexture(texture);

	// remove myself from the loaded resources
	for (size_t i = 0; i < loadedTextures.size(); i++) {
		if (loadedTextures.at(i) == this) {
			loadedTextures.erase(loadedTextures.begin() + i);
		}
	}
}

} /* namespace utils */

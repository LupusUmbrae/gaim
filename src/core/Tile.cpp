/*
 * Tile.cpp
 *
 *  Created on: 16 Nov 2013
 *      Author: Robin
 */

#include "core/Tile.h"

namespace core {

Tile::Tile(int x, int y, utils::Texture* texture) {
	this->x = x;
	this->y = y;
	this->texture = texture;
	this->setHeight(texture->getHeight());
	this->setWidth(texture->getWidth());
}

Tile::~Tile() {

}

void Tile::setRotation(double rotation) {
	this->rotation = rotation;
}

}

/*
 * Entity.h
 *
 *  Created on: 24 Jan 2014
 *      Author: Tom
 */

#ifndef ENTITY_H_
#define ENTITY_H_
#include "../utils/MapTextures.h"
#endif /* ENTITY_H_ */

#include "Aspect.h"

namespace core {

class Entity:public Aspect {

private:
	utils::Texture * texture = 0;
	int height;
	int width;

public:
	utils::Texture * getTexture() { return texture; }
	void setTexture(utils::Texture * texture) { this->texture = texture; }
	bool isTextured();

	int getHeight() { return height; }
	void setHeight(int height) { this->height = height;}

	int getWidth() { return width; }
	void setWidth(int width) { this->width = width;}

};


}

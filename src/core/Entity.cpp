/*
 * Entity.cpp
 *
 *  Created on: 25 Jan 2014
 *      Author: Tom
 */

#include "core/Entity.h"

namespace core {

bool Entity::isTextured()
{
	if (this->texture == 0) return false;
	return true;
}

}



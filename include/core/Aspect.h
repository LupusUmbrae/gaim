/*
 * Aspect.h
 *
 *  Created on: 24 Jan 2014
 *      Author: Tom
 */

#ifndef ASPECT_H_
#define ASPECT_H_

#endif /* ASPECT_H_ */

namespace core {

class Aspect {

private:
int x = 0;
int y = 0;

protected:
int getXPosition(){ return x;}
void setXPosition(int x){this->x = x;}

int getYPosition(){ return y;}
void setYPosition(int y){ this->y = y;}

};

}

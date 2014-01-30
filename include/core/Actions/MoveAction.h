/*
 * moveAction.h
 *
 *  Created on: 30 Jan 2014
 *      Author: Tom
 */

#ifndef MOVEACTION_H_
#define MOVEACTION_H_
#include "core/Action.h"

namespace core {
class MoveAction : public Action {
private:
	Moveable * mover;
	Vector * moveVector;

public:
	MoveAction(Moveable * mover, Vector * moveVector)
	{
		this->mover = mover;
		this->moveVector = moveVector;
	}

	void doAction(){
		mover->move(moveVector);
	}
};

class Moveable {
public:
	void move(Vector * v);
};
}

#endif /* MOVEACTION_H_ */

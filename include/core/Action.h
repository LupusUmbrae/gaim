/*
 * Interface.h
 *
 *  Created on: 27 Jan 2014
 *      Author: Tom
 */

#ifndef INTERFACE_H_
#define INTERFACE_H_

namespace core {

virtual class Action {

public:
	virtual void doAction() = 0;
	virtual ~Action() = 0;
};
}

#endif /* INTERFACE_H_ */

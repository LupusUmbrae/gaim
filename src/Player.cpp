/*
 * Player.cpp
 *
 *  Created on: 20 Jan 2014
 *      Author: Robin
 */

#include "Player.h"

Player::Player(utils::MapTexture* playerIcon) {
	this->playerIcon = playerIcon;

}

Player::~Player() {
	// TODO Auto-generated destructor stub
}

void Player::render() {
	playerIcon->render(x * scale, y * scale, 20, 20);
}

void Player::move(int x, int y) {
	this->x += x;
	this->y += y;
}

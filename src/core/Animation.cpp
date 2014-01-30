/*
 * Animation.cpp
 *
 *  Created on: 30 Jan 2014
 *      Author: Tom
 */

#include "core/Animation.h"

namespace core {

Animation::Animation(bool looped, bool oscillate, int maxFrames, utils::Texture * texture, int clipHeight, int clipWidth)
{
	this->looped = looped;
	this->oscillate = oscillate;
	this->maxFrames = maxFrames;
	this->textureMap = texture;
	this->clipHeight = clipHeight;
	this->clipWidth = clipWidth;
}

Animation::~Animation()
{
	delete(this->textureMap);
}


void Animation::onAnimate(int xPos, int yPos){
    if(oldTime + frameRate > SDL_GetTicks()) {
        return;
    }

    oldTime = SDL_GetTicks();
    if (!reversing) currentFrame++;
    else currentFrame--;

    if (oscillate && currentFrame == maxFrames) reversing = true;
    if (looped && currentFrame == maxFrames) currentFrame = 0;

    SDL_Rect clipPos;
    clipPos.h = clipHeight;
    clipPos.w = clipWidth;
    clipPos.y = (clipHeight * currentFrame);
    clipPos.x = 0;

    this->textureMap->render(xPos, yPos, 0, 0, &clipPos);
}

int Animation::getCurrentFrame(){
	return this->currentFrame;
}

utils::Texture * Animation::getTexture(){
	return this->textureMap;
}

bool Animation::isLooped(){
	return this->looped;
}

void Animation::setLoop(bool looped){
	this->looped = looped;
}

bool Animation::isFinished() {
	return (!this->looped && (oldTime > 0 && (currentFrame == maxFrames || currentFrame == 0)));
}

}




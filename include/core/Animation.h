/*
 * Animation.h
 *
 *  Created on: 30 Jan 2014
 *      Author: Tom
 */

#ifndef ANIMATION_H_
#define ANIMATION_H_

#include "Globals.h"
#include "utils/Texture.h"

namespace core {

class Animation {
private:
	unsigned int currentFrame = 0; // current frame
	int frameRate = FRAME_RATE; // millis
	unsigned int oldTime = 0; // previous time
	unsigned int maxFrames = 1; // maximum number of frames
	int clipHeight;
	int clipWidth;

	bool looped = false; // Whether to loop this animation
	bool oscillate = false; // Whether to oscillate this animation (e.g. frames 1,2,3,2,1)
	bool reversing = false; // Whether the animation is in the reverse part of the oscillation

	utils::Texture * textureMap;

public:
	Animation(bool looped, bool oscillate, int maxFrames, utils::Texture * texture, int clipHeight, int clipWidth);
	~Animation();
	void onAnimate(int xPos, int yPos);

	int getCurrentFrame();
	utils::Texture * getTexture();
	bool isLooped();
	void setLoop(bool looped);
	bool isFinished();
};
}

#endif /* ANIMATION_H_ */

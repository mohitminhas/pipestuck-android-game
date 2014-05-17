//
//  JetPack.cpp
//  PipeStuck
//
//
//

#include "JetPack.h"
#include "config.h"
#include "HelloWorldScene.h"

JetPack::JetPack()
{
			// It is the initial sprite of the jetpack boy
	initWithSpriteFrameName("jetpack1.png");
			this->runAction(boy()); //moving the boy

    status = isIdle;
	// initializing the score.
	    score = 0;
}

void JetPack::updateScore()
{
					score ++;
				((HelloWorld*)getParent())->updateUiScore();

    ((HelloWorld*)getParent())->playSound(SoundPoint);
}

// Function declaration for checking hit on Player
			void JetPack::hitMe()
{
    status = isHit;
    //GameOver tag is set to true
				((HelloWorld*)getParent())->GameOver = true;
				// Plays a beautiful sound on jetpack hit
    ((HelloWorld*)getParent())->playSound(SoundHit);

}

CCRepeatForever* JetPack::boy()

{
 // Total no. of sprites the jetpack player player have in animation
    int numframe = 5;
    CCArray* frames = CCArray::createWithCapacity(numframe);

    CCSpriteFrameCache* frameCache = CCSpriteFrameCache::sharedSpriteFrameCache();

		// Total 5 frame animtation for sprites.
    char file[100] = {0};
			for (int i = 0; i < numframe; i++)
    {
        sprintf(file, "jetpack%d.png", i+1);
				CCSpriteFrame* frame = frameCache->spriteFrameByName(file);
        frames->addObject(frame);
    }

				//Creating animation frames
		CCAnimation* animation = CCAnimation::createWithSpriteFrames(frames, FireUpInterval);
			CCAnimate* animate = CCAnimate::create(animation);

				CCRepeatForever* repeat = CCRepeatForever::create(animate);
		return repeat;
}

//Tapping the screen
	void JetPack::tapMe() {

		status = isTap;
			((HelloWorld*)getParent())->playSound(SoundTap);

}

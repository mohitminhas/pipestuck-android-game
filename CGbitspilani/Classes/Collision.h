//
//  Collision.h
//  PipeStuck
//
//
//

#ifndef __PipeStuck__Collision__
#define __PipeStuck__Collision__

#include <cocos2d.h>
#include "JetPack.h"

using namespace cocos2d;

class Collision : public CCComponent
{
		public:
			Collision(JetPack* jetpack, bool getScore); //Checking the score and position of the jetpack boy

private:
		CCNode* parent;
    JetPack* jetpack;
		bool getScore;

				virtual void update(float delta); //Checking collision and score

		bool isCollision(); //checking whether the collision has occured with pipes
		CCPoint getWorldPosition(); //Getting the world coordinate position of the jetpack boy
};

#endif /* defined(__PipeStuck__Collision__) */

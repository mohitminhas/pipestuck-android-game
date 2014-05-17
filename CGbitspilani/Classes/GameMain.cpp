//
//  GameMain.cpp
//  PipeStuck
//
//
//

#include "GameMain.h"
#include "config.h"
#include "HelloWorldScene.h"


// Action to be done in every Frame
void GameMain::actionMove()
{
    CCNode* parent = (CCNode*)getOwner();
    if (parent == NULL) return;

    //Constantly checks the value of the crows and spiders pipes
    float w = parent->boundingBox().size.width / Landfragments;
    CCMoveBy* moveleft = CCMoveBy::create(kParallaxDura, ccp(-w, 0));
    //The movement of the jetpack boy is 0 in horizontal direction
    CCMoveBy* moveright = CCMoveBy::create(0, ccp(w, 0));

	// Constantly slides the position of land to the left.
    CCRepeatForever* repeat = CCRepeatForever::create(CCSequence::create(moveleft, moveright, NULL));

    parent->runAction(repeat);

}

//Screen Frame Update

void GameMain::update(float delta)
{
			CCNode* parent = (CCNode*)getOwner();
    if (parent == NULL) return;

			// If game is over, then the game return to the original state, as it was when it was started.
					if ( ((HelloWorld*)parent->getParent())->GameOver )
				{
			parent->stopAllActions();
    }
}


	GameMain::GameMain()
{
    setName("GameMain");

}

		void GameMain::onEnter()
{
    actionMove();
}


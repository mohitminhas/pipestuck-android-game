//
//  Boy.cpp
//  PipeStuck
//
//
//

#include "Boy.h"
#include "config.h"

Boy::Boy()
{
    setName("Boy");
    curAction = NULL;

}


	void Boy::actionHit()
{
		CCPoint upPos = parent->getPosition();
    parent->stopAllActions();

    CCPoint downPos = ccp(upPos.x, LandPos);
		float intervalDown = getDuraDown(upPos, downPos) * 1/2; // going down with double speed

		CCMoveTo* movedown = CCMoveTo::create(intervalDown, downPos);
		CCRotateTo* facedown = CCRotateTo::create(intervalDown, 90);
    CCSpawn* fall = CCSpawn::create(facedown, CCEaseSineIn::create(movedown), NULL);

    curAction = fall;
		parent->runAction(fall);
}


	void Boy::stopAction()
{
		if (curAction != NULL)
    {	// This function call automatically stops all the actions, so that user cannot give input for thrusting the jetpack up.
					parent->stopAction(curAction);
			curAction = NULL;
		}
}


void Boy::actionTap()
{
			// Stop all the actions/activities on the screen.It is called when the jetpack boy dies.
				stopAction();

	// Statement to get the y coordinate of jetpack boy.
		CCPoint uppos = parent->getPosition();
			uppos.y += ThrustOffset;

		// After time DuraDown, the jetpack boy will come down to the position downpos, which is the bottom position.
    CCPoint downpos = ccp(uppos.x, LandPos);
		float intervalDown = getDuraDown(uppos, downpos);

				// Moving up the jetpack boy for intervaltion Kjumpinterval , by offset uppos
		CCMoveTo* moveup = CCMoveTo::create(ThrustDura, uppos);
    CCRotateTo* faceup = CCRotateTo::create(ThrustDura, -30);
			CCSpawn* fly = CCSpawn::create(faceup, CCEaseSineOut::create(moveup), NULL);



    CCMoveTo* movedown = CCMoveTo::create(intervalDown, downpos);

			CCRotateTo* facedown = CCRotateTo::create(intervalDown, 90);
		CCSpawn* fall = CCSpawn::create(facedown, CCEaseSineIn::create(movedown), NULL);

		CCSequence* tap = CCSequence::create(fly, fall, NULL);

    curAction = tap;
			parent->runAction(tap);

}

	void Boy::update(float delta)
{
			parent = (JetPack*)getOwner();
    if (parent == NULL) return;

			if (parent->status == isDie) //If the jetpack boy is not died, then it will return
    {
			return;
    }
		else if (parent->status == isTap) // Check whether the Tap flag is set.
    {
        parent->status = isIdle; // If the tap.
				actionTap();
    }
			else if (parent->status == isHit)
    {
        parent->status = isDie; // If touched the crows/spiders then killed
        actionHit(); //Call the action listner
    }
	}



float Boy::getDuraDown(CCPoint up, CCPoint down)
{

			float dy = up.y - down.y;
    float intervalDown;

		if (dy <= ThrustOffset) intervalDown = ThrustDura * 1/2;
		else
    {
				intervalDown = dy * (ThrustDura * 1/2) / ThrustOffset;
    }

		return intervalDown;
}

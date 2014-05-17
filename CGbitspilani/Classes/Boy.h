//
//  Boy.h
//  PipeStuck
//
//
//

#ifndef __PipeStuck__Boy__
#define __PipeStuck__Boy__

#include <cocos2d.h>
#include "JetPack.h"

using namespace cocos2d;

class Boy : public CCComponent
{
public:
    Boy();

    void actionTap(); // Some pre-defined functions to call action listner, if the single tap is done on screen.
    void actionHit();
    void stopAction();

private:

    JetPack* parent;
    virtual void update(float delta); // Constantly checking the status of the jetpack boy

    CCAction* curAction;

    float getDuraDown(CCPoint up, CCPoint down);

};

#endif /* defined(__PipeStuck__Boy__) */

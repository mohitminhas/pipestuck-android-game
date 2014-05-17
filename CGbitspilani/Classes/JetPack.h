//
//  JetPack.h
//  PipeStuck
//
//
//

#ifndef __PipeStuck__JetPack__
#define __PipeStuck__JetPack__

#include <cocos2d.h>

using namespace cocos2d;

// Defining status flags for the jetpack boy
typedef enum {

    isTap,
    isDie,
    isHit,
    isIdle,

}JetPackStatus;

class JetPack : public CCSprite
{
public:
    JetPack();

    JetPackStatus status;
	// Score of the jetpack boy
    int score;

    void tapMe();
    void hitMe();
    void updateScore();

private:

    CCRepeatForever* boy();

};


#endif /* defined(__PipeStuck__JetPack__) */

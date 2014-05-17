//
//  Parallax.h
//  PipeStuck
//
//
//

#ifndef __PipeStuck__Parallax__
#define __PipeStuck__Parallax__

#include <cocos2d.h>

using namespace cocos2d;

class Parallax : public CCComponent
{
public:
    Parallax(float w); // Moving the land toward left with value w

private:
    float w;
    virtual void onEnter(); // Move left in when the game begins
    virtual void update(float delta); // If game is over, then stop execution of updating land parallaxing.

    void actionMove();

};

#endif /* defined(__PipeStuck__Parallax__) */

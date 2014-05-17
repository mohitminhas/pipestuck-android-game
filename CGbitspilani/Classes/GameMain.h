//
//  GameMain.h
//  PipeStuck
//
//
//

#ifndef __PipeStuck__GameMain__
#define __PipeStuck__GameMain__

#include <cocos2d.h>

using namespace cocos2d;

class GameMain : public CCComponent
{
public:
    GameMain();
private:
    virtual void onEnter();
    virtual void update(float delta);

    void actionMove();
};

#endif /* defined(__PipeStuck__GameMain__) */

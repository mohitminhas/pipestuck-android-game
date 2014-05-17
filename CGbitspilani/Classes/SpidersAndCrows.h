//
//  SpidersAndCrows.h
//  PipeStuck
//
//
//

#ifndef __PipeStuck__SpidersAndCrows__
#define __PipeStuck__SpidersAndCrows__

#include <cocos2d.h>
#include "HelloWorldScene.h"

using namespace cocos2d;

class SpidersAndCrows : public CCComponent
{
public:
    SpidersAndCrows();
private:

    HelloWorld* parent;

    float interval; // Time to add pipe
    virtual void update(float delta);
};

#endif /* defined(__PipeStuck__SpidersAndCrows__) */

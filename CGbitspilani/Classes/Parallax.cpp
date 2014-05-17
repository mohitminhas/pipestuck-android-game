//
//  Parallax.cpp
//  PipeStuck
//
//
//

#include "Parallax.h"
#include "config.h"
#include "HelloWorldScene.h"

Parallax::Parallax(float w)
{
    setName("Parallax");
    this->w = w / Landfragments;
}


void Parallax::actionMove()
{
    CCNode* parent = (CCNode*)getOwner();
    CCMoveBy* moveleft = CCMoveBy::create(kParallaxDura, ccp(-w, 0));
    parent->runAction(CCRepeatForever::create(moveleft));
}

void Parallax::update(float delta)
{
    CCNode* parent = (CCNode*)getOwner();
    if (parent == NULL) return;

    if ( ((HelloWorld*)parent->getParent())->GameOver )
    {
        parent->stopAllActions();
    }
    //Remove spiders and crows from memory if they are out of screen
     CCArray* children = ((CCParallaxNode*)parent)->getChildren();

    if (children == NULL) return;
    for (int i = 0; i < children->count(); i++)
    {
        CCNode* child = (CCNode*)children->objectAtIndex(i);
        CCPoint cpos = ((CCParallaxNode*)parent)->convertToWorldSpace(child->getPosition());
        if (cpos.x < -child->boundingBox().size.width)
        {
            child->removeFromParentAndCleanup(true);
        }
    }

}

void Parallax::onEnter()
{
    actionMove();
}

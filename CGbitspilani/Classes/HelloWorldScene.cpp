#include "HelloWorldScene.h"
#include "config.h"
#include "SimpleAudioEngine.h"
#include "GameMain.h"
#include "Boy.h"
#include "Parallax.h"
#include "SpidersAndCrows.h"
#include "Collision.h"

USING_NS_CC;

using namespace cocos2d;

CCScene* HelloWorld::scene()
{
    // 'scene' is an autorelease object
    CCScene *scene = CCScene::create();

    // 'layer' is an autorelease object
    HelloWorld *layer = HelloWorld::create();

    // add layer as a child to scene
    scene->addChild(layer);

    // return the scene
    return scene;
}

// on "init" you need to initialize your instance
bool HelloWorld::init()
{
    //////////////////////////////
    // 1. super init first
    if ( !CCLayer::init() )
    {
        return false;
    }

    s = CCDirector::sharedDirector()->getWinSize();

	//Loading the sprite sheet's xml type format, to read it
    CCSpriteFrameCache::sharedSpriteFrameCache()->addSpriteFramesWithFile("sprites.plist");

	// Pre-loading the sound component.
	//Note: The components that are frequently used are kept in memory for better performance.
    CocosDenshion::SimpleAudioEngine::sharedEngine()->preloadEffect(SoundTap);
    CocosDenshion::SimpleAudioEngine::sharedEngine()->preloadEffect(SoundHit);
    CocosDenshion::SimpleAudioEngine::sharedEngine()->preloadEffect(SoundPoint);

    resetGame();
    this->addComponent(new SpidersAndCrows());

    return true;
}

void HelloWorld::resetGame()
{
    this->removeAllChildrenWithCleanup(true);

    GameOver = false;

    addBackground();
    addLand();
    addJetPack();
    addLayerParallax();
    addLabelScore();

}

void HelloWorld::addLabelScore()
{
    CCString* strp = CCString::createWithFormat("%d", jetpack->score);
    lbscore = CCLabelTTF::create(strp->getCString(), "", 30);//Creating and adding font.
    lbscore->setZOrder(getChildrenCount());
    lbscore->CCNode::setPosition(s.width/2, s.height - 20);

    this->addChild(lbscore);
}

void HelloWorld::updateUiScore()
{
    CCString* strp = CCString::createWithFormat("%d", jetpack->score);
    lbscore->setString(strp->getCString());
}

void HelloWorld::addBackground()
{
    CCSprite* bg = CCSprite::createWithSpriteFrameName("background.png");
    bg->CCNode::setPosition(s.width/2, s.height/2);
    this->addChild(bg);

}

void HelloWorld::addLand()
{
    land = CCSprite::createWithSpriteFrameName("land.png");
    land->setZOrder(2); // Set the layer of land as =2, for bringing parallax effect
    land->setAnchorPoint(ccp(0, 0.5));
    land->CCNode::setPosition(0, land->boundingBox().size.height/2 - 4);
    //Adding the component to the game screen.
    land->addComponent(new GameMain());

    this->addChild(land);

}


void HelloWorld::onEnter()
{
    CCDirector::sharedDirector()->getTouchDispatcher()->addTargetedDelegate(this, 0, true);
    CCLayer::onEnter();
}

void HelloWorld::onExit()
{
    CCDirector::sharedDirector()->getTouchDispatcher()->removeDelegate(this);
    CCLayer::onExit();
}


void HelloWorld::addLayerParallax()
{
    layerParallax = CCParallaxNode::create();
    layerParallax->addComponent(new Parallax(land->boundingBox().size.width) );
    this->addChild(layerParallax);
}

void HelloWorld::addSpidersAndCrows()
{

	//Random offset
    int r = rand();
    r = r%5;
    float dy = r * 10; //random 0, 10, 20, 30, 40


    r = rand();
    r = r%2;
    if (r==0) dy = -dy;


    // crows and spiders are added.

    CCSprite* crows = CCSprite::createWithSpriteFrameName("crows.png");
    CCPoint pos = ccp(s.width + crows->boundingBox().size.width/2,  //The space between two consequitive pipes
                      s.height/2 + crows->boundingBox().size.height/2
                      + kHoleBetweenPipe/2 + LandPos/2 + dy
                      );

	crows->setPosition(layerParallax->convertToNodeSpace(pos));

    CCSprite* spiders = CCSprite::createWithSpriteFrameName("spiders.png");
    pos.y = s.height/2 - spiders->boundingBox().size.height/2 - kHoleBetweenPipe + LandPos/2 + dy;
    spiders->setPosition(layerParallax->convertToNodeSpace(pos));


	//Setting the layer for crows and spider on different layers, for parallax effect
    crows->setZOrder(land->getZOrder() - 1); // The layer of crow is 1 less than layer of land, which is middle layer
    spiders->setZOrder(land->getZOrder() - 1);

    crows->addComponent(new Collision(jetpack, true));
    spiders->addComponent(new Collision(jetpack, false));

    layerParallax->CCNode::addChild(crows);
    layerParallax->CCNode::addChild(spiders);

}

void HelloWorld::addJetPack()
{
    jetpack = new JetPack();
    jetpack->setZOrder(1000);
    jetpack->CCNode::setPosition(s.width/2, s.height/2);

    jetpack->addComponent(new Boy());

    this->addChild(jetpack);
}

bool HelloWorld::ccTouchBegan(cocos2d::CCTouch *touch, cocos2d::CCEvent *event)
{
    if (GameOver)
    {
        resetGame();
    }
    else
    {
       jetpack->tapMe();
    }

    return true;
}


void HelloWorld::playSound(std::string name)
{
    CocosDenshion::SimpleAudioEngine::sharedEngine()->playEffect(name.c_str());
}

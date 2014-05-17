#ifndef __HELLOWORLD_SCENE_H__
#define __HELLOWORLD_SCENE_H__

#include "cocos2d.h"
#include "JetPack.h"

class HelloWorld : public cocos2d::CCLayer
{
public:
    // Here's a difference. Method 'init' in cocos2d-x returns bool, instead of returning 'id' in cocos2d-iphone
    virtual bool init();  

    // there's no 'id' in cpp, so we recommend returning the class instance pointer
    static cocos2d::CCScene* scene();
    
    // implement the "static node()" method manually
    CREATE_FUNC(HelloWorld);
    
    void addSpidersAndCrows();
    bool GameOver;
    void updateUiScore();
    
    void playSound(std::string name);

private:
    
    cocos2d::CCSize s; //Getting the screen size of the device
    cocos2d::CCSprite* land;
    JetPack* jetpack;
    CCParallaxNode* layerParallax;
    CCLabelTTF* lbscore;
    
    virtual void onEnter();
    virtual void onExit();
    virtual bool ccTouchBegan(cocos2d::CCTouch* touch, cocos2d::CCEvent* event);
    
    void addBackground();
    void addLand();
    void addJetPack();
    void addLayerParallax();
    void addLabelScore();

    void resetGame();

    
};

#endif // __HELLOWORLD_SCENE_H__

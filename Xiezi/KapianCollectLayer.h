//
//  KapianCollectLayer.h
//  Blackcat
//
//  Created by haojunhua on 14-1-15.
//
//

#ifndef Blackcat_KapianCollectLayer_h
#define Blackcat_KapianCollectLayer_h

#include "cocos2d.h"
USING_NS_CC;

class KapianCollectLayer: public CCLayer{
public:
    static KapianCollectLayer* create(CCSprite* collectedSprite);
    virtual bool init();
    void collectAnimate();
    void collectAnimateCallback();
    
private:
    CCSprite* m_collectedSprite;
    CCSprite* m_ka;
    CCSprite* m_chouti;
    
};

#endif

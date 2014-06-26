//
//  AchieveRewardLayer.h
//  Blackcat
//
//  Created by haojunhua on 14-6-16.
//
//

#ifndef __Blackcat__AchieveRewardLayer__
#define __Blackcat__AchieveRewardLayer__

#include "cocos2d.h"
USING_NS_CC;
#include "AchieveManager.h"

class AchieveRewardLayer:public CCLayerColor{
public:
    static AchieveRewardLayer* create(AchieveKey key,int level);
    
    virtual void setTarget(CCObject* target,SEL_CallFunc selector);
    
    virtual bool init(AchieveKey key,int level);
    
    void callback(float t);
protected:
    CCObject * m_target;
    SEL_CallFunc m_selector;
};

#endif /* defined(__Blackcat__AchieveRewardLayer__) */

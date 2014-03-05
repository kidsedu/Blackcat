//
//  Guide.h
//  Blackcat
//
//  Created by haojunhua on 13-12-26.
//
//

#ifndef Blackcat_Guide_h
#define Blackcat_Guide_h

#include "cocos2d.h"
USING_NS_CC;
#include <string.h>
using namespace std;

typedef enum{
    kGuideDialog=0,
    kGuideEvent
}GuideType;

typedef enum{
    kGuideEventDefault=-1,
    kGuideEventOpen=0,
    kGuideEventPass=1
}GuideEventStatus;

typedef enum{
    kGuideDialogOk=0,
    kGuideDialogYesOrNo,
    kGuideDialogHidden
}GuideDialogMode;

class Guide : public CCObject{
public:
    virtual ~Guide(){};
    
    //引导类型
    CC_SYNTHESIZE(int, m_type, Type);
    //下一个引导Dict对应的key，用于ok事件完成引导
    CC_SYNTHESIZE(string, m_toGuideKey, ToGuideKey);
};

class GuideDialog :public Guide{
public:
    GuideDialog(){
        m_type=kGuideDialog;m_tag=0;
        m_duration=0;
        m_text="";
        m_isAutoStep=false;
        m_mode=kGuideDialogOk;
        m_actionArray=CCArray::create();
        m_actionArray->retain();
        m_audioArray=CCArray::create();
        m_audioArray->retain();
    };
    
    ~GuideDialog(){CC_SAFE_RELEASE(m_actionArray);CC_SAFE_RELEASE(m_audioArray);}
    
    CC_SYNTHESIZE(int, m_tag, Tag);
    
    CC_SYNTHESIZE(float, m_duration, Duration);
    
    CC_SYNTHESIZE(string, m_text, Text);
    
    CC_SYNTHESIZE(bool, m_isAutoStep, IsAutoStep);
    
    CC_SYNTHESIZE(GuideDialogMode, m_mode, Mode);
    
    CC_SYNTHESIZE(CCArray*, m_actionArray, ActionArray);
    
    CC_SYNTHESIZE(CCArray*, m_audioArray, AudioArray);
    
};

class GuideEvent :public Guide{
public:
    GuideEvent(){m_type=kGuideEvent;};
    ~GuideEvent(){}
    CC_SYNTHESIZE(string, m_key, Key);
    CC_SYNTHESIZE(int, m_tag, Tag);
};

#endif
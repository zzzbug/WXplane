#ifndef __HELLOWORLD_SCENE_H__
#define __HELLOWORLD_SCENE_H__

#include "cocos2d.h"

class HelloWorld : public cocos2d::Layer
{
public:
    static cocos2d::Scene* createScene();

    virtual bool init();
    
    // a selector callback
	void menuCloseCallback(cocos2d::Ref* pSender);
    //刷新背景
	virtual void update(float delta);
	//创建主角
	virtual void hero();
	//创建子弹
	virtual void AddBullet(float dt);
	//创建敌机小
	virtual void AddEnemyS();
	//创建敌机中
	virtual void AddEnemyM();
	//创建敌机大
	virtual void AddEnemyB();
	//创建敌机子弹
	virtual void AddEnemyBullets(float x);
	virtual void AddEnemyBulletm(float x);
	virtual void AddEnemyBulletb(float x);
    // implement the "static create()" method manually
    CREATE_FUNC(HelloWorld);
};

#endif // __HELLOWORLD_SCENE_H__

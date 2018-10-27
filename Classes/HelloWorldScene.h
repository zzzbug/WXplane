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
    //ˢ�±���
	virtual void update(float delta);
	//��������
	virtual void hero();
	//�����ӵ�
	virtual void AddBullet(float dt);
	//�����л�С
	virtual void AddEnemyS();
	//�����л���
	virtual void AddEnemyM();
	//�����л���
	virtual void AddEnemyB();
	//�����л��ӵ�
	virtual void AddEnemyBullets(float x);
	virtual void AddEnemyBulletm(float x);
	virtual void AddEnemyBulletb(float x);
    // implement the "static create()" method manually
    CREATE_FUNC(HelloWorld);
};

#endif // __HELLOWORLD_SCENE_H__

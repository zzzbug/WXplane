#include "HelloWorldScene.h"

USING_NS_CC;

Scene* HelloWorld::createScene()
{
    // 'scene' is an autorelease object
    auto scene = Scene::create();
    
    // 'layer' is an autorelease object
    auto layer = HelloWorld::create();

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
    if ( !Layer::init() )
    {
        return false;
    }
    
    Size visibleSize = Director::getInstance()->getVisibleSize();
    Vec2 origin = Director::getInstance()->getVisibleOrigin();

	auto spbk = Sprite::create("images/background.png");
	spbk->setPosition(Vec2(visibleSize.width / 2 + origin.x, visibleSize.height / 2 + origin.y));
	spbk->setTag(1);
	this->addChild(spbk, 0);
	auto spbk_1 = Sprite::create("images/background.png");
	spbk_1->setPosition(Vec2(visibleSize.width / 2 + origin.x, visibleSize.height / 2 +600));
	spbk_1->setTag(2);
	this->addChild(spbk_1, 0);		
	//背景滚动
	this->update(1.0);
	//添加主角
	this->hero();
	//添加子弹
	this->schedule(schedule_selector(HelloWorld::AddBullet), 0.01f);
	//添加敌人
	this->AddEnemyS();
	this->AddEnemyM();
	this->AddEnemyB();

    /////////////////////////////
    // 2. add a menu item with "X" image, which is clicked to quit the program
    //    you may modify it.

    // add a "close" icon to exit the progress. it's an autorelease object
    auto closeItem = MenuItemImage::create(
                                           "CloseNormal.png",
                                           "CloseSelected.png",
                                           CC_CALLBACK_1(HelloWorld::menuCloseCallback, this));
    
	closeItem->setPosition(Vec2(origin.x + visibleSize.width - closeItem->getContentSize().width/2 ,
                                origin.y + closeItem->getContentSize().height/2));

    // create menu, it's an autorelease object
    auto menu = Menu::create(closeItem, NULL);
    menu->setPosition(Vec2::ZERO);
    this->addChild(menu, 1);

    /////////////////////////////
    // 3. add your codes below...

    // add a label shows "Hello World"
    // create and initialize a label
    
 /*   auto label = Label::createWithTTF("Play Plane", "fonts/Marker Felt.ttf", 24);
    
    // position the label on the center of the screen
    label->setPosition(Vec2(origin.x + visibleSize.width/2,
                            origin.y + visibleSize.height - label->getContentSize().height));

     //add the label as a child to this layer
    this->addChild(label, 1);*/
    
    return true;
}
void HelloWorld::hero() {
	auto hero = Sprite::create("images/me1.png");
	hero->setPosition(230, 60);
	hero->setTag(3);
	this->addChild(hero, 2);
	// now lets animate the sprite we moved
	Vector<SpriteFrame*> animFrames;
	animFrames.reserve(2);
	animFrames.pushBack(SpriteFrame::create("images/me1.png", Rect(0, 0, 100, 100)));
	animFrames.pushBack(SpriteFrame::create("images/me2.png", Rect(0, 0, 100, 100)));
	// create the animation out of the frames
	Animation* animation = Animation::createWithSpriteFrames(animFrames, 1);
	Animate* animate = Animate::create(animation);
	// run it and repeat it forever
	hero->runAction(RepeatForever::create(animate));

}
//创建子弹
void HelloWorld::AddBullet(float dt) {
	auto bullet = CCSprite::create("images/bullet1.png");
	bullet->setTag(4);
	auto hero = this->getChildByTag(3);
	bullet->setPosition(hero->getPosition().x-2, hero->getPosition().y);
	this->addChild(bullet, 1);
	CCAction* pAction = CCMoveTo::create(0.5f, ccp(hero->getPosition().x, 500));
	bullet->runAction(pAction);

}
//创建敌机小
void HelloWorld::AddEnemyS() {
	auto enemys = Sprite::create("images/enemy1.png");
	enemys->setPosition(100,450);
	enemys->setTag(6);
	this->addChild(enemys, 2);
	this->schedule(schedule_selector(HelloWorld::AddEnemyBullets),0.1f);

}
//创建敌机中
void HelloWorld::AddEnemyM() {
	auto enemym = Sprite::create("images/enemy2.png");
	enemym->setPosition(400, 350);
	enemym->setTag(7);
	this->addChild(enemym, 2);
	this->schedule(schedule_selector(HelloWorld::AddEnemyBulletm), 0.1f);
}
//创建敌机大
void HelloWorld::AddEnemyB() {
	auto enemyb = Sprite::create("images/enemy3_n1.png");
	enemyb->setPosition(250, 550);
	enemyb->setTag(8);
	this->addChild(enemyb, 2);
	this->schedule(schedule_selector(HelloWorld::AddEnemyBulletb), 0.1f);
}
//创建敌机子弹s
void HelloWorld::AddEnemyBullets(float x) {
	auto bullet = CCSprite::create("images/bullet2.png");
	auto hero = this->getChildByTag(6);
	bullet->setPosition(hero->getPosition().x - 2, hero->getPosition().y);
	this->addChild(bullet, 1);
	CCAction* pAction = CCMoveTo::create(0.5f, ccp(hero->getPosition().x,0));
	bullet->runAction(pAction);
}
//创建敌机子弹z
void HelloWorld::AddEnemyBulletm(float x) {
	auto bullet = CCSprite::create("images/bullet2.png");
	auto hero = this->getChildByTag(7);
	bullet->setPosition(hero->getPosition().x - 2, hero->getPosition().y);
	this->addChild(bullet, 1);
	CCAction* pAction = CCMoveTo::create(0.5f, ccp(hero->getPosition().x, 0));
	bullet->runAction(pAction);
}
//创建敌机子弹da
void HelloWorld::AddEnemyBulletb(float x) {
	auto bullet = CCSprite::create("images/bullet2.png");
	auto hero = this->getChildByTag(8);
	bullet->setPosition(hero->getPosition().x - 2-50, hero->getPosition().y);
	this->addChild(bullet, 1);
	CCAction* pAction = CCMoveTo::create(0.5f, ccp(hero->getPosition().x, 50));
	bullet->runAction(pAction);

	auto bullet2 = CCSprite::create("images/bullet2.png");
	bullet2->setPosition(hero->getPosition().x - 2, hero->getPosition().y);
	this->addChild(bullet2, 1);
	CCAction* pAction1 = CCMoveTo::create(0.5f, ccp(hero->getPosition().x, 50));
	bullet2->runAction(pAction1);

	auto bullet1 = CCSprite::create("images/bullet2.png");
	bullet1->setPosition(hero->getPosition().x - 2+50, hero->getPosition().y);
	this->addChild(bullet1, 1);
	CCAction* pAction2 = CCMoveTo::create(0.5f, ccp(hero->getPosition().x, 50));
	bullet1->runAction(pAction2);
}


void HelloWorld::update(float delta){
	auto spbk = this->getChildByTag(1);
	auto spbk_1 = this->getChildByTag(2);
	// 滚动动作
	auto mt = MoveBy::create(10, Vec2(0, -450));
	auto ta = TargetedAction::create(spbk, mt);
	auto ta2 = TargetedAction::create(spbk_1, mt->clone());
	// 同时执行
	auto spawn = Spawn::createWithTwoActions(ta, ta2);
	// 重复执行，设定位置
	auto rf = RepeatForever::create(Sequence::createWithTwoActions(spawn, CallFunc::create([=]()
	{
		//this->stopAllActions();
		spbk->setPositionY(300);
		spbk_1->setPositionY(850);
		//log("----");
	})));
	// 当前Layer执行这个Action
	this->runAction(rf);
}


void HelloWorld::menuCloseCallback(Ref* pSender)
{
	//auto hero = this->getChildByTag(8);
	//this->removeChildByTag(8);

   // Director::getInstance()->end();

#if (CC_TARGET_PLATFORM == CC_PLATFORM_IOS)
    exit(0);
#endif
}

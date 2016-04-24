#include "HelloWorldScene.h"

#include "cocos2d.h"


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


	double alto = visibleSize.height;
	double ancho = visibleSize.width;
	
	////////////////////////////////////
	//Musica
	//auto audio = SimpleAudioEngine::getInstance();
	//audio->playBackgroundMusic("mymusic.mp3", true);

    /////////////////////////////LOGO
	//CREATE LOGO
	auto logo = Sprite::create("HelloWorld.png");
	logo->setAnchorPoint(Vec2(0,0));
	logo->setPosition( Vec2(ancho*0.5 - logo->getContentSize().width*0.5, alto*0.8 - logo->getContentSize().height*0.5) );

	//ANIMACION LOGO
	////Repeticion Infinita !!
	auto fadeIn = FadeIn::create(5.0f);
	logo->runAction(fadeIn);

	auto fadeOut = FadeOut::create(10.0f);
	auto delay = DelayTime::create(2);

	auto action = (ActionInterval*)Sequence::create(fadeIn,delay, fadeOut,delay, NULL);
	logo->runAction(RepeatForever::create(action));

	this->addChild(logo, 1);

	////////////////////////////////////////////////////////////////////////////////
	
    auto closeItem = MenuItemImage::create(
                                           "CloseNormal.png",
                                           "CloseSelected.png",
                                           CC_CALLBACK_1(HelloWorld::menuCloseCallback, this));
    
	closeItem->setPosition(Vec2(origin.x + visibleSize.width - closeItem->getContentSize().width/2 , origin.y + closeItem->getContentSize().height/2));

    // create menu, it's an autorelease object
    auto menu = Menu::create(closeItem, NULL);
    menu->setPosition(Vec2::ZERO);
    this->addChild(menu, 1);
	///////////////////////////////////////////////////////////////////////////////////
	//MENU PAPU

	Vector <MenuItem*> MenuItems;
	
	auto nuevo = MenuItemImage::create("boton/Normal.png", "boton/Press.png", CC_CALLBACK_1(HelloWorld::noHaceNada, this));
	nuevo->setPosition(Vec2(origin.x ,origin.y- alto*0.2));
	//nuevo->addChild(nuevo, 1);
	MenuItems.pushBack(nuevo);

	
	auto lvl = MenuItemImage::create("boton/Normal.png", "boton/Press.png", CC_CALLBACK_1(HelloWorld::noHaceNada, this));
	lvl->setPosition(Vec2(origin.x, origin.y - alto*0.3));
	//lvl->addChild(lvl, 1);
	MenuItems.pushBack(lvl);

	auto credito = MenuItemImage::create("boton/Normal.png", "boton/Press.png", CC_CALLBACK_1(HelloWorld::noHaceNada, this));
	credito->setPosition(Vec2(origin.x, origin.y - alto*0.4));
	//credito->addChild(credito,1);
	MenuItems.pushBack(credito);
	
	
	//miMenu->setAnchorPoint(Vec2::ZERO);
	//miMenu->setPosition(Vec2(ancho*0.5 - miMenu->getContentSize().width*0.5, alto*0.4 - miMenu->getContentSize().height*0.5));

	auto miMenu = Menu::createWithArray(MenuItems);
	this->addChild(miMenu, 1);


	/*
    /////////////////////////////
    // 3. add your codes below...

    // add a label shows "Hello World"
    // create and initialize a label
    
    auto label = Label::createWithTTF("Hello World", "fonts/Marker Felt.ttf", 24);
    
    // position the label on the center of the screen
    label->setPosition(Vec2(origin.x + visibleSize.width/2,
                            origin.y + visibleSize.height - label->getContentSize().height));

    // add the label as a child to this layer
    this->addChild(label, 1);

    // add "HelloWorld" splash screen"
    auto sprite = Sprite::create("HelloWorld.png");

    // position the sprite on the center of the screen
    sprite->setPosition(Vec2(visibleSize.width/2 + origin.x, visibleSize.height/2 + origin.y));

    // add the sprite as a child to this layer
    this->addChild(sprite, 0);
    */
    return true;
}


void HelloWorld::menuCloseCallback(Ref* pSender)
{
    Director::getInstance()->end();

#if (CC_TARGET_PLATFORM == CC_PLATFORM_IOS)
    exit(0);
#endif
}

void HelloWorld::noHaceNada(Ref* pSender)
{

}


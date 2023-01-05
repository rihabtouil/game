/****************************************************************************
 Copyright (c) 2017-2018 Xiamen Yaji Software Co., Ltd.
 
 http://www.cocos2d-x.org
 
 Permission is hereby granted, free of charge, to any person obtaining a copy
 of this software and associated documentation files (the "Software"), to deal
 in the Software without restriction, including without limitation the rights
 to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 copies of the Software, and to permit persons to whom the Software is
 furnished to do so, subject to the following conditions:
 
 The above copyright notice and this permission notice shall be included in
 all copies or substantial portions of the Software.
 
 THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
 THE SOFTWARE.
 ****************************************************************************/

#include "level3.h"
#include"winner.h"
#include"GameOver.h"
#include"AudioEngine.h"


USING_NS_CC;


     
    
 Scene* Level3::createScene()
{
     
    auto scene = Scene::createWithPhysics();

    //scene->getPhysicsWorld()->setDebugDrawMask(PhysicsWorld::DEBUGDRAW_ALL); //line dyal physics node 
    scene->getPhysicsWorld()->setGravity(Vec2(0, -400));
    // 'layer' is an autorelease object
    auto layer = Level3::create();
    layer->SetPhysicsWorld(scene->getPhysicsWorld());
    // add layer as a child to scene
    scene->addChild(layer);

	// return the scene
	return scene;
}

 bool Level3::init()
 {
     if (!Layer::init())
     {
         return false;
     }

     Size visibleSize = Director::getInstance()->getVisibleSize();
     Point origin = Director::getInstance()->getVisibleOrigin();
     //--------------------------------------------------------------
  
     auto edgeBody = PhysicsBody::createEdgeBox(visibleSize, PHYSICSBODY_MATERIAL_DEFAULT, 3);

     auto edgeNode = Node::create();

     edgeNode->setPosition(Point(visibleSize.width / 2 + origin.x, visibleSize.height / 2 + origin.y));
     edgeNode->setPhysicsBody(edgeBody);
     this->addChild(edgeNode);

     bg = Sprite::create("bg.png");
     bg->setPosition(Point((visibleSize.width / 2) + origin.x, (visibleSize.height / 2) + origin.y));
     this->addChild(bg);

     auto label = Label::createWithSystemFont("Level 3", "Arial", 24);
     label->setPosition(Point((visibleSize.width / 2) + origin.x, (visibleSize.height / 2) + origin.y + 280));
     this->addChild(label);
     {
         hero1 = Sprite::create("carac.png");
         hero1->setPosition(Point(70, 110));


         auto heroBody1 = PhysicsBody::createBox(hero1->getContentSize() / 2);

         hero1->setPhysicsBody(heroBody1);

         heroBody1->setContactTestBitmask(true);

         heroBody1->setTag(1);


         this->addChild(hero1);

     }
     {
         gr1 = Sprite::create("gr.png");
         gr1->setPosition(Point(110, 100));
         auto grBody1 = PhysicsBody::createBox(gr1->getContentSize());
         gr1->setPhysicsBody(grBody1);
         grBody1->setDynamic(false);
         this->addChild(gr1);
     }

     {
         gr2 = Sprite::create("teil.png");
         gr2->setPosition(Point(380, 180));
         auto grBody2 = PhysicsBody::createBox(gr2->getContentSize());
         gr2->setPhysicsBody(grBody2);
         grBody2->setDynamic(false);
         this->addChild(gr2);
     }
     {
         coin1 = Sprite::create("coin.png");
         coin1->setPosition(Point(380, 240));
         auto coinBody1 = PhysicsBody::createCircle(coin1->getContentSize().width / 6, PhysicsMaterial(0, 0, 0));
         coin1->setPhysicsBody(coinBody1);
         coinBody1->setDynamic(false);
         coinBody1->setContactTestBitmask(true);

         coinBody1->setTag(2);
         this->addChild(coin1);


     }
     {
         ball1 = Sprite::create("ball.png");

         ball1->setPosition(Point(280, 580));
         auto ballBody1 = PhysicsBody::createBox(ball1->getContentSize());
         ball1->setPhysicsBody(ballBody1);

         auto firstMvt = MoveTo::create(3.0, Point(280, 570));
         auto secondMvt = MoveTo::create(3.0, Point(280, 20));

         auto seq = Sequence::create(firstMvt, secondMvt, nullptr);
         auto re = RepeatForever::create(seq);

         ball1->runAction(re);

         ballBody1->setDynamic(false);
         ballBody1->setContactTestBitmask(true);
         ballBody1->setTag(3);

         this->addChild(ball1);
     }

     {
         ball2 = Sprite::create("ball.png");

         ball2->setPosition(Point(490, 30));
         auto ballBody2 = PhysicsBody::createBox(ball2->getContentSize());
         ball2->setPhysicsBody(ballBody2);

         auto firstMvt = MoveTo::create(3.0, Point(480, 20));
         auto secondMvt = MoveTo::create(3.0, Point(480, 570));

         auto seq = Sequence::create(firstMvt, secondMvt, nullptr);
         auto re = RepeatForever::create(seq);

         ball2->runAction(re);

         ballBody2->setDynamic(false);
         ballBody2->setContactTestBitmask(true);
         ballBody2->setTag(6);

         this->addChild(ball2);
     }

     {
         gr3 = Sprite::create("teil.png");
         gr3->setPosition(Point(580, 260));
         auto grBody3 = PhysicsBody::createBox(gr3->getContentSize());
         gr3->setPhysicsBody(grBody3);
         grBody3->setDynamic(false);
         this->addChild(gr3);
     }
     {
         coin2 = Sprite::create("coin.png");
         coin2->setPosition(Point(580, 320));
         auto coinBody2 = PhysicsBody::createCircle(coin1->getContentSize().width / 6, PhysicsMaterial(0, 0, 0));
         coin2->setPhysicsBody(coinBody2);
         coinBody2->setDynamic(false);
         coinBody2->setContactTestBitmask(true);

         coinBody2->setTag(5);
         this->addChild(coin2);


     }
     {
         ball3 = Sprite::create("ball.png");

         ball3->setPosition(Point(700, 580));
         auto ballBody3 = PhysicsBody::createBox(ball3->getContentSize());
         ball3->setPhysicsBody(ballBody3);

         auto firstMvt = MoveTo::create(3.0, Point(700, 570));
         auto secondMvt = MoveTo::create(3.0, Point(700, 20));

         auto seq = Sequence::create(firstMvt, secondMvt, nullptr);
         auto re = RepeatForever::create(seq);

         ball3->runAction(re);

         ballBody3->setDynamic(false);
         ballBody3->setContactTestBitmask(true);
         ballBody3->setTag(7);

         this->addChild(ball3);
     }
     {
         gr4 = Sprite::create("gr.png");
         gr4->setPosition(Point(900, 320));
         auto grBody4 = PhysicsBody::createBox(gr4->getContentSize());
         gr4->setPhysicsBody(grBody4);
         grBody4->setDynamic(false);
         this->addChild(gr4);
     }
     {
         tv = Sprite::create("dist.png");
         tv->setPosition(Point(980, 410));
         auto tvBody = PhysicsBody::createBox(tv->getContentSize());
         tv->setPhysicsBody(tvBody);
         tvBody->setDynamic(false);
         tvBody->setContactTestBitmask(true);
         tvBody->setTag(4);
         this->addChild(tv);

         auto label = Label::createWithSystemFont("insert your coin!", "Arial", 13);
         label->setPosition(Point(960, 498));
         this->addChild(label);
     }
     auto  keyboardListener = EventListenerKeyboard::create();

     keyboardListener->onKeyPressed = [=](EventKeyboard::KeyCode keyCode, Event* event)
     {
         switch (keyCode)
         {

         case EventKeyboard::KeyCode::KEY_UP_ARROW:
             posY += 4.0f;
             break;

         case EventKeyboard::KeyCode::KEY_LEFT_ARROW:
             posX-= 3.0f;
             break;

         case EventKeyboard::KeyCode::KEY_RIGHT_ARROW:
             posX += 3.0f;
             break;
         }

     };

     keyboardListener->onKeyReleased = [=](EventKeyboard::KeyCode keyCode, Event* event)
     {
         switch (keyCode)
         {

         case EventKeyboard::KeyCode::KEY_UP_ARROW:
             posY-= 4.0f;
             break;

         case EventKeyboard::KeyCode::KEY_LEFT_ARROW:
             posX += 3.0f;
             break;

         case EventKeyboard::KeyCode::KEY_RIGHT_ARROW:
             posX -= 3.0f;
             break;
         }
     };

     this->_eventDispatcher->addEventListenerWithSceneGraphPriority(keyboardListener, this);
     this->scheduleUpdate();

     auto contactListener = EventListenerPhysicsContact::create();
     contactListener->onContactBegin = CC_CALLBACK_1(Level3::onContact, this);
     this->getEventDispatcher()->addEventListenerWithSceneGraphPriority(contactListener, this);
     return true;

 }

 
 
 void Level3::update(float dt)
 {
     float newPosX = Level3::hero1->getPositionX() + (posX);
     float newPosY = Level3::hero1->getPositionY() + (posY);

     Level3::hero1->setPosition(newPosX, newPosY);

     if (newPosY < 80)
     {
         AudioEngine::play2d("error.mp3", false, 1.0f);
         auto scene = GameOver::createScene();
         Director::getInstance()->replaceScene(scene);
     }
 }

 
   
 bool Level3::onContact(cocos2d::PhysicsContact& contact)
 {
     PhysicsBody* bodyA = contact.getShapeA()->getBody();
     PhysicsBody* bodyB = contact.getShapeB()->getBody();

     if ((bodyA->getTag() == 1 && bodyB->getTag() == 2) ||
         (bodyA->getTag() == 2 && bodyB->getTag() == 1))
     {
         AudioEngine::play2d("Coin-Echo.mp3", false, 1.0f);
         coin1->removeFromParent();
         count++;

     }

     if ((bodyA->getTag() == 1 && bodyB->getTag() == 5) ||
         (bodyA->getTag() == 5 && bodyB->getTag() == 1))
     {
         AudioEngine::play2d("Coin-Echo.mp3", false, 1.0f);
         coin2->removeFromParent();
         count++;

     }
     //damage
     if ((bodyA->getTag() == 1 && bodyB->getTag() == 3) ||
         (bodyA->getTag() == 3 && bodyB->getTag() == 1))
     {
         AudioEngine::play2d("error.mp3", false, 1.0f);
         auto scene = GameOver::createScene();
         Director::getInstance()->replaceScene(scene);

     }
     if ((bodyA->getTag() == 1 && bodyB->getTag() == 6) ||
         (bodyA->getTag() == 6 && bodyB->getTag() == 1))
     {
         AudioEngine::play2d("error.mp3", false, 1.0f);
         auto scene = GameOver::createScene();
         Director::getInstance()->replaceScene(scene);

     }
     if ((bodyA->getTag() == 1 && bodyB->getTag() == 7) ||
         (bodyA->getTag() == 7 && bodyB->getTag() == 1))
     {
         AudioEngine::play2d("error.mp3", false, 1.0f);
         auto scene = GameOver::createScene();
         Director::getInstance()->replaceScene(scene);

     }
     //next 
     if ((bodyA->getTag() == 1 && bodyB->getTag() == 4) ||
         (bodyA->getTag() == 4 && bodyB->getTag() == 1))
     {
         auto  keyboardListener = EventListenerKeyboard::create();
         keyboardListener->onKeyPressed = [=](EventKeyboard::KeyCode keyCode, Event* event)
         {
             if (keyCode == EventKeyboard::KeyCode::KEY_ENTER && count == 2)
             {
                 AudioEngine::play2d("coinsplash.mp3", false, 1.0f);
                 auto scene = Win::createScene();
                 Director::getInstance()->replaceScene(scene);

             }

         };
         this->_eventDispatcher->addEventListenerWithSceneGraphPriority(keyboardListener, this);
         this->scheduleUpdate();
     }
     return true;
 }



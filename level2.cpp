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

#include "level2.h"
#include"level3.h"
#include"GameOver.h"
#include"AudioEngine.h"


USING_NS_CC;


     
    
 Scene* Level2::createScene()
{
     
    auto scene = Scene::createWithPhysics();

    //scene->getPhysicsWorld()->setDebugDrawMask(PhysicsWorld::DEBUGDRAW_ALL); //line dyal physics node 
    scene->getPhysicsWorld()->setGravity(Vec2(0, -500));
    // 'layer' is an autorelease object
    auto layer = Level2::create();
    layer->SetPhysicsWorld(scene->getPhysicsWorld());
    // add layer as a child to scene
    scene->addChild(layer);

	// return the scene
	return scene;
}

 bool Level2::init()
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
     auto label = Label::createWithSystemFont("Level 2", "Arial", 24);
     label->setPosition(Point((visibleSize.width / 2) + origin.x, (visibleSize.height / 2) + origin.y + 280));
     this->addChild(label);

     {
         hero1 = Sprite::create("carac.png");
         hero1->setPosition(Point(70, 220));


         auto heroBody1 = PhysicsBody::createBox(hero1->getContentSize() / 2);

         hero1->setPhysicsBody(heroBody1);

         heroBody1->setContactTestBitmask(true);

         heroBody1->setTag(1);
       

         this->addChild(hero1);

     }


     {
         gr1 = Sprite::create("gr.png");
         gr1->setPosition(Point(900, 210));
         auto grBody1 = PhysicsBody::createBox(gr1->getContentSize());
         gr1->setPhysicsBody(grBody1);
         grBody1->setDynamic(false);
         this->addChild(gr1);
     }
     {
         tv = Sprite::create("dist.png");
         tv->setPosition(Point(980, 300));
         auto tvBody = PhysicsBody::createBox(tv->getContentSize());
         tv->setPhysicsBody(tvBody);
         tvBody->setDynamic(false);
         tvBody->setContactTestBitmask(true);
         tvBody->setTag(4);
         this->addChild(tv);

         auto label = Label::createWithSystemFont("insert your coin", "Arial", 13);
         label->setPosition(Point(955, 397));
         this->addChild(label);
     }
     {
         gr2 = Sprite::create("gr.png");
         gr2->setPosition(Point(110, 210));
         auto grBody2 = PhysicsBody::createBox(gr2->getContentSize());
         gr2->setPhysicsBody(grBody2);
         grBody2->setDynamic(false);
         this->addChild(gr2);
     }

     {
         gr3 = Sprite::create("teil.png");
         gr3->setPosition(Point(330, 290));
         auto grBody3 = PhysicsBody::createBox(gr3->getContentSize());
         gr3->setPhysicsBody(grBody3);
         grBody3->setDynamic(false);
         this->addChild(gr3);
     }
      {
      gr4 = Sprite::create("ball.png");
     
      gr4->setPosition(Point(995, 380));
      auto bgBody4 = PhysicsBody::createBox(gr4->getContentSize());
      gr4->setPhysicsBody(bgBody4);

      auto firstMvt = MoveTo::create(5.0, Point(10, 380));
      auto secondMvt = MoveTo::create(5.0, Point(1000, 380));

     auto seq = Sequence::create(firstMvt, secondMvt,nullptr);
      auto re = RepeatForever::create(seq);

      gr4->runAction(re);

      bgBody4->setDynamic(false);
      bgBody4->setContactTestBitmask(true);
      bgBody4->setTag(3);
  
     this->addChild(gr4);
  }
      {
          coin1 = Sprite::create("coin.png");
          coin1->setPosition(Point(330, 350));
          auto coinBody1 = PhysicsBody::createCircle(coin1->getContentSize().width / 6, PhysicsMaterial(0, 0, 0));
          coin1->setPhysicsBody(coinBody1);
          coinBody1->setDynamic(false);
          coinBody1->setContactTestBitmask(true);

          coinBody1->setTag(2);
          this->addChild(coin1);


      }
      {
          gr3 = Sprite::create("teil.png");
          gr3->setPosition(Point(579, 193));
          auto grBody3 = PhysicsBody::createBox(gr3->getContentSize());
          gr3->setPhysicsBody(grBody3);
          grBody3->setDynamic(false);
          this->addChild(gr3);
      }

       {
          coin2 = Sprite::create("coin.png");
          coin2->setPosition(Point(583, 250));
          auto coinBody2 = PhysicsBody::createCircle(coin2->getContentSize().width / 6, PhysicsMaterial(0, 0, 0));
          coin2->setPhysicsBody(coinBody2);
          coinBody2->setDynamic(false);
          coinBody2->setContactTestBitmask(true);

          coinBody2->setTag(5);
          this->addChild(coin2);


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
             posX -= 3.0f;
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
             posY -= 4.0f;
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
     contactListener->onContactBegin = CC_CALLBACK_1(Level2::onContact, this);
     this->getEventDispatcher()->addEventListenerWithSceneGraphPriority(contactListener, this);

 
     return true;
 }

 void Level2::update(float dt)
 {
     float newPosX = Level2::hero1->getPositionX() + (posX);
     float newPosY = Level2::hero1->getPositionY() + (posY);

     Level2::hero1->setPosition(newPosX, newPosY);

     if (newPosY < 90)
     {
         AudioEngine::play2d("error.mp3", false, 1.0f);
         auto scene = GameOver::createScene();
         Director::getInstance()->replaceScene(scene);
     }
 }
 bool Level2::onContact(cocos2d::PhysicsContact& contact)
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
     //next 
     if ((bodyA->getTag() == 1 && bodyB->getTag() == 4) ||
         (bodyA->getTag() == 4 && bodyB->getTag() == 1))
     {
         auto  keyboardListener = EventListenerKeyboard::create();
         keyboardListener->onKeyPressed = [=](EventKeyboard::KeyCode keyCode, Event* event)
         {
             if (keyCode == EventKeyboard::KeyCode::KEY_ENTER && count==2)
             {
                 AudioEngine::play2d("coinsplash.mp3", false, 1.0f);
                 auto scene = Level3::createScene();
                 Director::getInstance()->replaceScene(scene);
             }

         };
         this->_eventDispatcher->addEventListenerWithSceneGraphPriority(keyboardListener, this);
         this->scheduleUpdate();
     }
     return true;
 }


 
   
   


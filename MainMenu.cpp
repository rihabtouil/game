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

#include "MainMenu.h"
#include"GameOver.h"
#include"level2.h"
#include"AudioEngine.h"


USING_NS_CC;

Scene* NewScene::createScene()
{
     
    auto scene = Scene::createWithPhysics();

  // scene->getPhysicsWorld()->setDebugDrawMask(PhysicsWorld::DEBUGDRAW_ALL);  
    scene->getPhysicsWorld()->setGravity(Vec2(0, -500));
   
    auto layer = NewScene::create();
    layer->SetPhysicsWorld(scene->getPhysicsWorld());
   
    scene->addChild(layer);

	
	return scene;
}


bool NewScene::init()
{
	
	if (!Layer::init())
	{
		return false;
	}

	Size visibleSize = Director::getInstance()->getVisibleSize();
	Point origin = Director::getInstance()->getVisibleOrigin();
	
	


	mySprite = Sprite::create("bg.png");
    mySprite->setPosition(Point((visibleSize.width / 2) + origin.x, (visibleSize.height / 2) + origin.y));
    this->addChild(mySprite);
	
    auto label = Label::createWithSystemFont("Level 1", "Arial", 24);
    label->setPosition(Point((visibleSize.width / 2) + origin.x, (visibleSize.height / 2) + origin.y +280));
    this->addChild(label);
   
    //-----------------------------------------------------
    auto edgeBody = PhysicsBody::createEdgeBox(visibleSize, PHYSICSBODY_MATERIAL_DEFAULT, 3);

    auto edgeNode = Node::create();

    edgeNode->setPosition(Point(visibleSize.width / 2 + origin.x, visibleSize.height / 2  + origin.y ));
    edgeNode->setPhysicsBody(edgeBody);
    this->addChild(edgeNode);
    


  
     {
          hero1 = Sprite::create("carac.png");
          hero1->setPosition(Point(70, 220));
          
         
          auto heroBody1 = PhysicsBody::createBox(hero1->getContentSize()/2);
         
          hero1->setPhysicsBody(heroBody1);
         
          heroBody1->setContactTestBitmask(true);

          heroBody1->setTag(1);
         

         this->addChild(hero1);

      }

   
    {
         coin1 = Sprite::create("coin.png");
         coin1->setPosition(Point(460,330));
         auto coinBody1 = PhysicsBody::createCircle(coin1->getContentSize().width/6 , PhysicsMaterial(0, 0, 0));
         coin1->setPhysicsBody(coinBody1);
         coinBody1->setDynamic(false);
         coinBody1->setContactTestBitmask(true);

         coinBody1->setTag(2);
         this->addChild(coin1);
         

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
         tv->setPosition(Point(979, 300));
         auto tvBody = PhysicsBody::createBox(tv->getContentSize());
         tv->setPhysicsBody(tvBody);
         tvBody->setDynamic(false);
         tvBody->setContactTestBitmask(true);
         tvBody->setTag(4);
         this->addChild(tv);

         auto label = Label::createWithSystemFont("insert your coin!", "Arial", 13);
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
         gr3 = Sprite::create("gr.png");
         gr3->setPosition(Point(460, 270));
         auto grBody3 = PhysicsBody::createBox(gr3->getContentSize());
         gr3->setPhysicsBody(grBody3);
         grBody3->setDynamic(false);
  
         this->addChild(gr3);
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
     contactListener->onContactBegin = CC_CALLBACK_1(NewScene::onContact, this);
     this->getEventDispatcher()->addEventListenerWithSceneGraphPriority(contactListener, this);
 
	   return true;
	}

   
   void NewScene::update(float dt)
    {
        float newPosX = NewScene::hero1->getPositionX() + (posX);
        float newPosY = NewScene::hero1->getPositionY() + (posY);

        NewScene::hero1->setPosition(newPosX, newPosY);
        if (newPosY < 90)
        {
            AudioEngine::play2d("error.mp3", false, 1.0f);
            auto scene = GameOver::createScene();
            Director::getInstance()->replaceScene(scene);
           
        }
      
    }



   
   bool NewScene::onContact(cocos2d::PhysicsContact& contact)
   {
       PhysicsBody *bodyA = contact.getShapeA()->getBody();
       PhysicsBody *bodyB = contact.getShapeB()->getBody();
       
       if ((bodyA->getTag() == 1 && bodyB->getTag() == 2) ||
           (bodyA->getTag() == 2 && bodyB->getTag() == 1))
       {
           AudioEngine::play2d("Coin-Echo.mp3", false, 1.0f);
           coin1->removeFromParent();
           count++; 

       }
   
       //next 
       if ((bodyA->getTag() == 1 && bodyB->getTag() == 4) ||
           (bodyA->getTag() == 4 && bodyB->getTag() == 1))
       {
           auto  keyboardListener = EventListenerKeyboard::create();
           keyboardListener->onKeyPressed = [=](EventKeyboard::KeyCode keyCode, Event* event)
           {
               if (keyCode == EventKeyboard::KeyCode::KEY_ENTER && count==1)
               {
                   AudioEngine::play2d("coinsplash.mp3", false, 1.0f);
                   auto scene = Level2::createScene();
                   Director::getInstance()->replaceScene(scene);
               }

           };
           this->_eventDispatcher->addEventListenerWithSceneGraphPriority(keyboardListener, this);
           this->scheduleUpdate();
       }
       return true;
       }
         
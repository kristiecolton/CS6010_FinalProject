//
//  Main.cpp
//  Gal
//
//  Created by Braden McClean on 9/22/20.
//
#include <iostream>
#include <stdio.h>
#include <SFML/Graphics.hpp>
#include "SpaceShipPlayer.cpp"
#include "Projectiles.cpp"
#include"GalacticaClass.cpp"
int main()
{
    // create the window
    float windowX=2800;
    sf::RenderWindow window(sf::VideoMode(windowX, 3000), "My window");

    //create my space ship boi
   
    spaceShip player=spaceShip("GalagaSpaceShip.png",1450,1400);
    vector<Projectiles> spaceShipMissles;
    vector<Projectiles> enemyLasers;
    // Create a vector of enemies
    vector<Enemy> enemies;
    float x = 500;
    float y = 50;
    for (int i = 0; i < 10; i++) {
        Enemy myEnemy = Enemy("spaceinvader.png", x, y);
        enemies.push_back(myEnemy);
        x += 200;
    }
  
    
    // create enemy squad instance using vector of enemies
    EnemySquad myEnemySquad(enemies);
    
    // run the program as long as the window is open
    while (window.isOpen())
       {
           
           // check all the window's events that were triggered since the last iteration of the loop
           sf::Event event;
           while (window.pollEvent(event))
           {
               // "close requested" event: we close the window
               if (event.type == sf::Event::Closed)
               {
                   window.close();
               }
               if (event.type == sf::Event::KeyPressed)
                {
                    if (event.key.code==sf::Keyboard::D)
                    {;

                        //this if statment sees if the key is pressed and
                        //keeps the speed to a max velocity
                        if (event.key.code==sf::Keyboard::D&& player.velocity<player.maxPostiveVelocity)
                        {
                            //the velocity and the accleration are in
                            //the class
                            player.velocity+=player.postiveAccleration;
                            player.checkBoundandMove(windowX);
                        }
                        else
                        {
                            //keeps the thing moveing after reaching maxVelocity
                            player.checkBoundandMove(windowX);
                        }
                
                    }
                    if (event.key.code==sf::Keyboard::A)
                    {
                        
                        //flip all the signs
                        if (event.key.code==sf::Keyboard::A&& player.velocity>player.maxNegativeVelocity)
                        {
                            //the velocity and the accleration are in
                            //the class
                            player.velocity+=player.negativeAccleration;
                             player.checkBoundandMove(windowX);
                        }
                        else
                        {
                            //keeps the thing moveing after reaching maxVelocity
                             player.checkBoundandMove(windowX);
                        }
                    }
                 if (event.key.code==sf::Keyboard::W)
                 {
                     Projectiles myProjectiles =Projectiles("spaceShipProjectile.png",(player.pSprite.getPosition().x+42),(player.pSprite.getPosition().y-35));
                     spaceShipMissles.push_back(myProjectiles);
                     
                     
                 }
                }
              
           
                
           }

           // clear the window with black color
           window.clear(sf::Color::Black);

       // set the shape color to green
           
       // Draw the enemy squad in the window
       myEnemySquad.drawEnemySquad(window);
        //slowly changes ship speeITS SUPER RAD
          //needs to be in this or the players speed looks like shit
           //KNOWN BUG some rounding issue is causing sometimes the ship to driffed right
        player.velocityToZero();
        player.checkBoundandMove(windowX);

        // Move the enemy squad
        myEnemySquad.checkBoundandMove(windowX);

        //Draws the spaceShip
        player.drawSpaceShip(window);
           vector<int> checkingMissles={};
        for (int i=0;i<spaceShipMissles.size();i++)
        {
            bool flag=false;
           spaceShipMissles[i].drawProjectile(window);
            flag=spaceShipMissles[i].checkBoundandMove(windowX,myEnemySquad.myEnemySquad);

            
            
            //test the boundry of the missles PLEASE SHOOT ONLY ONE
//            cout<< spaceShipMissles[i].pSprite.getGlobalBounds().top<<"left"<<endl;
        
            if (flag==true)
            {
            checkingMissles.push_back(i);
            }
        }
           for (int i=0;i<checkingMissles.size();i++)
           {
               //erase the missles when they hit something that destories it
               //we had a problem that when you delete in your ShipMisssles vector
               //you would shift all the postions right
               //causing you checking missles to be one off after the first itteration
               //so -i big brain time
               spaceShipMissles.erase(spaceShipMissles.begin()+(checkingMissles[i]-i));
           }

//    cout<< myEnemySquad.myEnemySquad[0].pSprite.getGlobalBounds().top+myEnemySquad.myEnemySquad[0].pSprite.getGlobalBounds().height<<"right"<<endl;
//       // end the current frame
       window.display();
           
       }
    return 0;
}

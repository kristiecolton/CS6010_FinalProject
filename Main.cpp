//
//  Main.cpp
//  Gal
//
//  Created by Braden McClean on 9/22/20.
//
#include <iostream>
#include <stdio.h>
#include <SFML/Graphics.hpp>
#include "GalacticaClass.cpp"
#include "EnemiesClass.cpp"
#include "SpaceShipPlayer.cpp"
#include "Projectiles.cpp"
int main()
{
    // create the window
    float windowX=2800;
    sf::RenderWindow window(sf::VideoMode(windowX, 3000), "My window");

    //create my space ship boi
   
    spaceShip player=spaceShip("GalagaSpaceShip.png",1450,1400);
       Projectiles spaceShipMissle=Projectiles("spaceShipProjectile.png",1600,(1400));
    // Create a vector of enemies
    vector<Enemy> enemies;
    float x = 500;
    float y = 50;
    for (int i = 0; i < 10; i++) {
        Enemy myEnemy = Enemy("spaceinvader.png", x, y);
        enemies.push_back(myEnemy);
        x += 200;
    }
  
    
    // Ok weird bug: if I create this enemy (but don't actuallly do anything with it), all the enemies in the Enemies vector are drawn properly (on line 72). If I delete this enemy, the texture of each enemy in the enemies vector disappears
     Enemy enemy1 = Enemy("spaceinvader.png", 300, 300);

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
       
           
        //Draws the spaceShip
           player.drawSpaceShip(window);
           
           spaceShipMissle.drawProjectile(window);
       // end the current frame
       window.display();
       }
    return 0;
}

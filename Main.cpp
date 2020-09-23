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

int main()
{
    // create the window
    sf::RenderWindow window(sf::VideoMode(2800, 3000), "My window");

    sf::CircleShape shape(50.f);
    
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
           shape.move(sf::Vector2f(.001,0));
           
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
                    {
                        shape.move(sf::Vector2f(5,0));
                    }
                    if (event.key.code==sf::Keyboard::A)
                    {
                        shape.move(sf::Vector2f(-5,0));
                    }
                }
           }

           // clear the window with black color
           window.clear(sf::Color::Black);

       // set the shape color to green
       shape.setFillColor(sf::Color(50, 100, 100));

       window.draw(shape);
           
       // Draw the enemy squad in the window
       myEnemySquad.drawEnemySquad(window);

       // end the current frame
       window.display();
       }
    return 0;
}

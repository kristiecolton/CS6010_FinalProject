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
int main()
{
  // create the window
       sf::RenderWindow window(sf::VideoMode(2800, 3000), "My window");
       // run the program as long as the window is open
      sf::CircleShape shape(50.f);
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
       // end the current frame
           window.display();
       }
    return 0;
}

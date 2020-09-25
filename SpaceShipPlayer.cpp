//
//  SpaceShipPlayer.cpp
//  ALL_BUILD
//
//  Created by Braden McClean on 9/22/20.
//
#include <iostream>
#include <stdio.h>
#include <SFML/Graphics.hpp>
using namespace std;
class spaceShip
{
    
public:
    
    sf::Sprite pSprite;
    sf::Texture pTexture;
    bool isShot;
    
    // Member variables for smooth movement
    float velocity;
    float maxPostiveVelocity=20;
    float maxNegativeVelocity=-20;
    float postiveAccleration=2;
    float negativeAccleration=-2;
      
    
    /* Default Constructor */
    spaceShip() {
        
    }
    
    /* Constructor */
    spaceShip(string imgPath, float x, float y)
    {
        // If image for texture not found, print an error
        if (!pTexture.loadFromFile(imgPath))
        {
            cout << "Error! Cannot find image SpaceShip." << endl;
        }
        
        // Set the texture for the sprite
        pSprite.setTexture(pTexture);
           
        // Set the size of the sprite
        pSprite.setScale(sf::Vector2f(0.1,0.1));
           
        // Set the position of the sprite
        pSprite.setPosition(x, y);
           
    }
    
    // Decelerate Spaceship smoothly
    void velocityToZero()
    {
        if (velocity>0)
        {
            velocity*=.75;
        }
        
        if(velocity<0)
        {
            velocity*=.75;
        }
    
    }
    
    // Ensures spaceship stays within bounds of window, move spaceship
    void checkBoundandMove(float x)
    {
        // if spaceship hits left side of screen
        if( pSprite.getPosition().x<25)
        {
          // Force Spaceship to remain in position
          pSprite.setPosition(25,1400);
        }
        // If spaceship hits the right side of the screen
        else if (pSprite.getPosition().x>x-125)
        {
            // Force spaceship to remain in position
            pSprite.setPosition(x-125,1400);
        }
        
        pSprite.move(velocity, 0);
    }
    
    /* Draw Spaceship to a given window reference*/
    void drawSpaceShip(sf::RenderWindow &window)
    {
        if(isShot==false)
        {
        window.draw(pSprite);
        }
    }
};


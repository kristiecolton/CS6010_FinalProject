//
//  Projectiles.cpp
//  Gal
//
//  Created by Braden McClean on 9/23/20.
//

#include <stdio.h>
#include <SFML/Graphics.hpp>
#include <iostream>
#include"EnemiesClass.cpp"
#include "SpaceShipPlayer.cpp"

using namespace std;
class Projectiles
{
public:
    
    sf::Texture* pTexture;
    sf::Sprite pSprite;
       
    /* Default Constructor*/
    Projectiles() {
        
    }
    
    /* Constructor */
    // Uses imgpath for texture, uses x and y to position projectile in the window
    Projectiles(string imgPath, float x, float y)
    {
          
        // Create texture object
        pTexture = new sf::Texture;
        
        // If image for texture not found, print an error
        if (!pTexture->loadFromFile(imgPath))
        {
            cout << "Error! Cannot find image Projectile in "<< imgPath<<"." << endl;
        }
        
        // Set the texture for the sprite
        pSprite.setTexture(*pTexture);
           
        // Set the size of the enemy laser
        if (imgPath=="enemyProjectile.png")
        {
            pSprite.setScale(sf::Vector2f(0.15,0.15));
        }
        // Set the size of the spaceship projectile
        else
        {
            pSprite.setScale(sf::Vector2f(0.05,0.05));
        }
        
        // Set the position of the sprite
        pSprite.setPosition(x, y);
           
    }
    
   // Moves missile a few pixels upward, returns true if missile reaches top of screen
    bool checkBoundandMove(float x,vector<Enemy>& group)
    {
        // bool to indicate if Spaceship has been shot
        bool flag = false;
        //if the sprite hits the top of the screen, flag is true
        if(pSprite.getPosition().y<0)
        {
            flag=true;
            return flag;
        }
        // Loops through the vector of enemies and checks if missile has hit any of them. If so, mark enemy as shot and set flag to true
        for (int i=0; i<group.size(); i++)
        {
            if(pSprite.getGlobalBounds().intersects(group[i].getSprite().getGlobalBounds())&&group[i].isShot==false)
            {
                group[i].isShot=true;
                flag=true;
                return flag;
            }
        }
        
        // Move the missile upwards
        pSprite.move(0, -2);
        
        return flag;
    }
    
  // Moves enemy laser a few pixels downward, returns true if laser reaches bottom of screen or shoots spaceship
  bool checkBoundandMoveLaser(float y,spaceShip& player)
     {
         bool flag = false;
         
         // if the laser hits the bottom of the screen, set flag to true
         if(pSprite.getPosition().y>y)
         {
             flag=true;
             return flag;
         }
         
         // ifa the laser hits the spaceship, mark spaceship as shot and set flag to true
         if(pSprite.getGlobalBounds().intersects(player.pSprite.getGlobalBounds())&& player.isShot==false)
         {
             player.isShot=true;
             flag=true;
             return flag;
         }
         // Move laser downward
         pSprite.move(0, 1);
         
         return flag;
     }
    
    // Draws the projectile to the given window
    void drawProjectile(sf::RenderWindow &window)
       {
           window.draw(pSprite);
       }
};

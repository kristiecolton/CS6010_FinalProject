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
using namespace std;
class Projectiles
{public:
    //default constructor
    Projectiles() {
        
    }
    
    
    //USE RIGHT IMGPATH FOR ENEMY AND PLAYER

    Projectiles(string imgPath, float x, float y) {
          
        // Look up texture constructor
        pTexture = new sf::Texture;
        
        // If image for texture not found, print an error
        
        // If image for texture not found, print an error
            if (!pTexture->loadFromFile(imgPath)) {
                cout << "Error! Cannot find image Projectile in "<< imgPath<<"." << endl;
            }
           // Set the texture for the sprite
           pSprite.setTexture(*pTexture);
           
           // Set the size of the sprite
           pSprite.setScale(sf::Vector2f(0.05,0.05));
           
           // Set the position of the sprite
           pSprite.setPosition(x, y);
           
       }
    
   
    bool checkBoundandMove(float x,vector<Enemy> group)
    {
        bool flag = false;
        //if the sprite hits the top of the screen flag false
        if( pSprite.getPosition().y<0)
        {
            //moving 0 didnt work so I FORCED IT TO BE THERE
            flag=true;
        }
//        for (int i=0;i<group.size();i++)
//        {
//            if(group[i].getSprite().getGlobalBounds().intersects(pSprite.getGlobalBounds()));
//            {
//                flag=true;
//                return flag;
//            }
//        }
        pSprite.move(0, -2);
        return flag;
    }
    
    sf::Texture* pTexture;
    sf::Sprite pSprite;
    //to kill the missle when it hits something
    bool hasHit;
    
    void drawProjectile(sf::RenderWindow &window)
       {
           window.draw(pSprite);
       }
    
    
};

//
//  EnemiesClass.cpp
//  Gal
//
//  Created by Kristina Colton on 9/22/20.
//
#include <SFML/Graphics.hpp>
#include <iostream>
#include <stdio.h>
#include <string>
using namespace std;

// Not going to lie. No idea what this does but tutorial says I need this.

class Enemy
{
public:
    
    /* Default Constructor */
    Enemy() {
        
    }
    
    /* Constructor */
    Enemy(string imgPath) {
        // If image for texture not found, print an error
        if (!pTexture.loadFromFile(imgPath)) {
            cout << "Error! Cannot find image." << endl;
        }
        // Set the texture for the sprite
        pSprite.setTexture(pTexture);
    }
    
    /* Takes a window (by reference) as an argument and draws sprite to window*/
    void drawEnemy(sf::RenderWindow &window)
    {
        window.draw(pSprite);
    }
    

    
private:
    sf::Texture pTexture;
    sf::Sprite pSprite;
};


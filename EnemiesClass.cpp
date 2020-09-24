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
    // Takes an imgPath to use as sprite texture, and an x and y coordinate position to place sprite
    Enemy(string imgPath, float x, float y) {
        // Look up texture constructor
        pTexture = new sf::Texture;
        
        // If image for texture not found, print an error
        if (!pTexture->loadFromFile(imgPath)) {
            cout << "Error! Cannot find image." << endl;
        }
        // Set the texture for the sprite
        pSprite.setTexture(*pTexture);
        
        // Set the size of the sprite
        pSprite.setScale(sf::Vector2f(0.1,0.1));
        
        // Set the position of the sprite
        pSprite.setPosition(x, y);
        
    }
    
    /* Draw sprite to a given window reference*/
    void drawEnemy(sf::RenderWindow &window)
    {
        window.draw(pSprite);
    }
    
    sf::Sprite getSprite() {
        return pSprite;
    }
    
private:
    
    sf::Texture* pTexture;
    sf::Sprite pSprite;
    bool isShot;
};


class EnemySquad {
public:
    
    vector<Enemy> myEnemySquad;
    
    /* Default Constructor */
    EnemySquad() {
        
    }
    
    /* Constructor */
    EnemySquad(vector<Enemy> enemies) {
        myEnemySquad = enemies;
    }
    
    
    void drawEnemySquad(sf::RenderWindow &window)
    {
        for (Enemy e : myEnemySquad) {
            e.drawEnemy(window);
        }
    }
    
    Enemy operator[](int index) {
        return myEnemySquad[index];
    }
        
    
private:
    
};




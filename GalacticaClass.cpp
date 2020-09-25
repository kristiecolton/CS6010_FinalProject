#include <SFML/Graphics.hpp>
#include <iostream>
#include "Projectiles.cpp"

struct galacticaGame
{
    // Returns true if all enemies have been shot
    bool winChecker(vector<Enemy> &goons)
    {
        for (int i=0;i<goons.size();i++)
        {
            if (goons[i].isShot==false)
                return false;
        }
        return true;
        
    }
    
    // Checks if Spaceship has been shot
    bool loseChecker(spaceShip &player)
    {
        return player.isShot;
    }
    
   void enemyShooter (EnemySquad &myEnemySquad,vector<Projectiles>&enemyLasers)
    {
        for (int i=0;i<myEnemySquad.myEnemySquad.size();i++)
        {
            // If randomly selected enemy is not shot, shoot laser from enemy
            if (myEnemySquad[i].randomGeneratorForEnemies()&&myEnemySquad[i].isShot==false)
            {
                // Create the laster
                Projectiles enemyLaser =Projectiles("enemyProjectile.png",(myEnemySquad[i].pSprite.getPosition().x+42),(myEnemySquad[i].pSprite.getPosition().y+35));
                // Add laser to vector of existing enemy lasers
                enemyLasers.push_back(enemyLaser);
            }
        }
    }

};

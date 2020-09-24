#include <SFML/Graphics.hpp>
#include <iostream>
#include "Projectiles.cpp"
struct galacticaGame
{
    bool winChecker(vector<Enemy> &goons)
    {
        for (int i=0;i<goons.size();i++)
        {
            if (goons[i].isShot==false)
                return false;
        }
        return true;
        
    }
    bool loseChecker(spaceShip &player)
    {
        return player.isShot;
    }
   void enemyShooter (EnemySquad &myEnemySquad,vector<Projectiles>&enemyLasers)
      {
      
      for (int i=0;i<myEnemySquad.myEnemySquad.size();i++)
                {
                    if (myEnemySquad[i].randomGeneratorForEnemies()&&myEnemySquad[i].isShot==false)
                    {
                        Projectiles enemyLaser =Projectiles("enemyProjectile.png",(myEnemySquad[i].pSprite.getPosition().x+42),(myEnemySquad[i].pSprite.getPosition().y+35));
                        enemyLasers.push_back(enemyLaser);
                    }
                }
      
      }

};

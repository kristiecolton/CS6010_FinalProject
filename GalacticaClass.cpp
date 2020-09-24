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
   
};

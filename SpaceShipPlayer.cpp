//
//  SpaceShipPlayer.cpp
//  ALL_BUILD
//
//  Created by Braden McClean on 9/22/20.
//

#include <stdio.h>
#include <SFML/Graphics.hpp>
sf::Texture spaceShipText;
struct spaceShip
{

    
    
    
    
    void spriteMaker()
    {
        if (!spaceShipText.loadFromFile("GalagaSpaceShip.png"))
        {
        std::cout<<"Your texture didnt load"<<endl;

        }
    }
};
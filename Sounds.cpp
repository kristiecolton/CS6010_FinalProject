//
//  Sounds.cpp
//  Gal
//
//  Created by Braden McClean on 9/24/20.
//
#include <iostream>
#include <stdio.h>
#include <SFML/Audio.hpp>
using namespace std;

struct soundEffect
{
    sf::SoundBuffer buffer;
    sf::Sound sound;
    
    /* Default Constructor */
    soundEffect()
    {
        if (!buffer.loadFromFile("pew.wav"))
        {
            cout<<"SOUND BROKE GO FIX IT"<<endl;
        }
        
        sound.setBuffer(buffer);
    }
    
};


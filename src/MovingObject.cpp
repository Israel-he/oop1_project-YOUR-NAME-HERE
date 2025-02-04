#pragma once
#include "MovingObject.h"
#include <GameControl.h>

MovingObject::MovingObject(sf::Vector2f position, const char type)
    :GameObject(position, type)
{
}

sf::Vector2f MovingObject::getPosition() const
{
    return m_position;
}

float MovingObject::getDistance() 
{ 
    return 0.0f;
}

void MovingObject::setPoint(int point)
{
}

void MovingObject::setLife(int life) {
    // Implementation of the function
    // For example, you can set a member variable to the given life value
   int m_life = life;
}




 

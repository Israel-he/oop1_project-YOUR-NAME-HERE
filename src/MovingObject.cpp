#include "MovingObject.h"

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




 

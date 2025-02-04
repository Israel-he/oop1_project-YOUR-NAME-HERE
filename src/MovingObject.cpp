#pragma once
#include "MovingObject.h"
#include <GameControl.h>

MovingObject::MovingObject(sf::Vector2f position, const char type)
    :GameObject(position, type), m_firstPosition(position)
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

void MovingObject::setFirstLoc()
{
}

void MovingObject::setfreezeDuration(int deltaTime) {
    m_freezeDuration = deltaTime;
}

void MovingObject::setLife(int life) {
    // Implementation of the function
    // For example, you can set a member variable to the given life value
   int m_life = life;
}

int MovingObject::getLife()
{
    return 0;
}

bool MovingObject::getFreezeDuration(){
    return m_freezeDuration;
}

bool MovingObject::isFrozen() const {
    return m_frozen;
}

void MovingObject::ResetLocition()
{
}


// הגדרה של הפונקציה Frozen
bool MovingObject::Frozen() const {
    return m_frozen;
}
 

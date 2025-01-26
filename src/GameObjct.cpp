#include "GameObject.h"

GameObject::GameObject(const sf::Vector2f& pos, const char type)
    :m_position(pos)
{
    m_Object.setTexture(getTexture(type));
    m_Object.setPosition(m_position);
}

//====================================
 
//==================position===========================
void GameObject::setPosition(const sf::Vector2f& newPos)
{
    m_position = newPos;
}

sf::Vector2f GameObject::getPosition() const
{
    return m_position;
}

//===================================================

#include "GameObject.h"

GameObject::GameObject(const sf::Vector2f& pos, const char type)
    :m_position(pos), m_isDispose(false)//,m_loadTexture(*(new LoadTexture))
{
    m_Object.setTexture(m_loadTexture.getTexture(type));
    m_Object.setPosition(m_position);
}

LoadTexture GameObject::m_loadTexture = LoadTexture();
//====================================
 
//
//sf::Sprite& GameObject::getSprit() const {
//    return const_cast<sf::Sprite&>(m_Object); // Return the sprite
//}

bool GameObject::checkCollision(const GameObject& other) const
{
    if (&other == this) return false;

    // Always return true just for demonstrating the collision handling
    // The commented-out line is probably what you want in the actual game
    return true;
    // return m_rectangle.getGlobalBounds().intersects(other.getGlobalBounds());
}
//===================getSprite===================
sf::Sprite& GameObject::getSprit()  
{
    return m_Object;
}

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
bool GameObject::getIsdispose()
{
    return m_isDispose;
}
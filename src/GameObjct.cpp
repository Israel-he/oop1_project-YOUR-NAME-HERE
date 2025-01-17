#include "GameObject.h"


GameObject::GameObject(const sf::Vector2f& pos,const char type)
    :m_position(pos)
{
    m_Object.setTexture(getTexture(type));
    m_Object.setPosition(m_position);
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

//==================Handles collisions================
bool GameObject::checkCollision(const GameObject& other) const
{
    if (other.getPosition() == m_position)  // getPosition()
        return true;

    return false;
}
//=======================draw==========================
void GameObject::draw(sf::RenderWindow& window)
{
    window.draw(m_Object);
}
//=====================================================





//void GameObject::setSymbol(sf::Texture sym)
//{
//
//    symbol.setTexture(sym);
//}
//
//sf::Sprite GameObject::getSymbol() const
//{
//    return symbol;
//}
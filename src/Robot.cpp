#include "Robot.h"

Robot::Robot(sf::Vector2f position,const char type)
	:MovingObject(position,type),m_point(0),m_life(0)
{
}

//====================draw============================
void Robot::draw(sf::RenderWindow& window) 
{
    window.draw(m_Object);
}

//==================The point=========================
void Robot::setPoint(int point)
{
	m_point += point;
}

int Robot::getPoint()
{
	return m_point;
}

//================position of the robot===============
void Robot::setPosition(sf::Vector2f position)
{
	m_position = position;
}
//===============================================

sf::Vector2f Robot::getPosition()
{
	return m_position;
}

//=====================move======================================
void Robot::move(float m_deltaTime)
{
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up)) {
        m_Object.move(0, -moveSpeed * m_deltaTime);
        m_position.y -= moveSpeed * m_deltaTime;

    }
    else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down)) {
        m_Object.move(0, moveSpeed * m_deltaTime);
        m_position.y += moveSpeed * m_deltaTime;
    }
    else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) {
        m_Object.move(-moveSpeed * m_deltaTime, 0);
        m_position.x -= moveSpeed * m_deltaTime;
    }
    else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) {
        m_Object.move(moveSpeed * m_deltaTime, 0);
        m_position.x += moveSpeed * m_deltaTime;
    }
    else 
        captuareLocition();
}


//=========================captuareLocition==============
void Robot::captuareLocition()//מחשב את השארית ומאפס אותה לפי הצורך
{
    if(static_cast<int>(m_position.x) % 50 < 7)
        m_position.x -= static_cast<int>(m_position.x) % 50;

    if (static_cast<int>(m_position.y) % 50 < 7)
    m_position.y -= static_cast<int>(m_position.y) % 50;

    if (static_cast<int>(m_position.x) % 50 > 43)
    {
        m_position.x += (50 - (static_cast<int>(m_position.x) % 50));
    }
    if (static_cast<int>(m_position.y) % 50 > 43)
        m_position.y += (50 - (static_cast<int>(m_position.y) % 50));

    m_Object.setPosition(m_position);
}
 
//===================checkCollision=======================
//bool Robot::checkCollision(sf::Sprite& other)
//{
//    return  m_Object.getGlobalBounds().intersects(
//           other.getGlobalBounds());
//}

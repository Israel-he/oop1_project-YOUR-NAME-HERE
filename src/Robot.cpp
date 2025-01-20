#include "Robot.h"

Robot::Robot(sf::Vector2f position,const char type)
	:GameObject(position,type),m_event(),m_point(0)
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
	return  m_position;
} 

//=====================move======================================
void Robot::move(sf::Event& event,float m_deltaTime)
{
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up)) {
        m_Object.move(0, -moveSpeed * m_deltaTime);
    }
    else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down)) {
        m_Object.move(0, moveSpeed * m_deltaTime);
    }
    else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) {
        m_Object.move(-moveSpeed * m_deltaTime, 0);
    }
    else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) {
        m_Object.move(moveSpeed * m_deltaTime, 0);
    }
}
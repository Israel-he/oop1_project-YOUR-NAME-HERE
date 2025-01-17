#include "Robot.h"

Robot::Robot(sf::Vector2f position,const char type)
	:GameObject(position,type),m_event(),m_point(0)
{
	 
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
//====================================================


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

 

//=========================draw==================================
//void Robot::draw(sf::RenderWindow& window)
//{
//	window.draw(m_Object);
//}

//=====================move======================================
void Robot::move(sf::Event& event,float m_deltaTime)
{

    // חישוב הזמן שחלף (Delta Time)
    //m_deltaTime = m_clock.restart().asSeconds();


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










/*

    float deltaTime = m_clock.restart().asSeconds();
    switch (event.type)
    {
    case sf::Event::KeyPressed:
        if (event.key.code == sf::Keyboard::Up)
            m_robot.move(0, -moveSpeed * deltaTime);
        else if (event.key.code == sf::Keyboard::Down)
            m_robot.move(0, moveSpeed * deltaTime);
        else if (event.key.code == sf::Keyboard::Left)
            m_robot.move(-moveSpeed * deltaTime, 0);
        else if (event.key.code == sf::Keyboard::Right)
            m_robot.move(moveSpeed * deltaTime, 0);
        break;
    }*/
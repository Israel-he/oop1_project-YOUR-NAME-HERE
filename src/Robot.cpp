#include "Robot.h"
#include <iostream>

Robot::Robot(sf::Vector2f position,const char type)
	:MovingObject(position,type),m_point(0),m_life(5)
{
    m_fontLifeNum.loadFromFile("arial.ttf");
    m_textLifeNum.setCharacterSize(30);
    m_textLifeNum.setFont(m_fontLifeNum);
    m_textLifeNum.setFillColor(sf::Color::Red);
    m_textLifeNum.setString(std::to_string(m_life));
    m_textLifeNum.setPosition(80.f, 10.f);

    m_fontLife.loadFromFile("arial.ttf");
    m_textLife.setCharacterSize(30);
    m_textLife.setFont(m_fontLife);
    m_textLife.setFillColor(sf::Color::Red);
    m_textLife.setString("Life: ");
    m_textLife.setPosition(20.f, 10.f);

}

//====================draw============================
void Robot::draw(sf::RenderWindow& window) 
{
    window.draw(m_Object);
    window.draw(m_textLifeNum);
    window.draw(m_textLife);
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

//=================checkCollision========
// bool Robot::checkCollision(float deltaTime)
//{
//    return false;
//}

 //=============================================
void Robot::handleCollision(GameObject& gameObject)  
{
    // double dispatch
    gameObject.handleCollision(*this);
}
//==============================================
 void Robot::handleCollision(Wall& gameObject)
 {
     std::cout << "in collotion1 \n";
     m_canMove = true;
 }

 void Robot::handleCollision(Rock& gameObject)
 {
 }

//=====================move======================================
void Robot::move(sf::Vector2f position,float deltaTime)
{
    if (!m_canMove)
    {
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up)) {
            m_Object.move(0, -moveSpeed * deltaTime);
            m_position.y -= moveSpeed * deltaTime;

        }
        else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down)) {
            m_Object.move(0, moveSpeed * deltaTime);
            m_position.y += moveSpeed * deltaTime;
        }
        else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) {
            m_Object.move(-moveSpeed * deltaTime, 0);
            m_position.x -= moveSpeed * deltaTime;
        }
        else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) {
            m_Object.move(moveSpeed * deltaTime, 0);
            m_position.x += moveSpeed * deltaTime;
        }
        else
        {
            captuareLocition();
        }
    }
    else
    {
        roundLoction();
        m_canMove = false;
       /* int x = (m_position.x + 15) / 50;
        int y = (m_position.y + 15) / 50;

        x *= 50;
        y *= 50;
        m_position = sf::Vector2f((float)x, (float)y);
        m_Object.setPosition(m_position);*/
    }
   
}


//=========================captuareLocition==============*
void Robot::captuareLocition()//מחשב את השארית ומאפס אותה לפי הצורך
{
    if (static_cast<int>(m_position.x) % 50 < 7)
        m_position.x -= (static_cast<int>(m_position.x) % 50);

    if (static_cast<int>(m_position.y) % 50 < 7)
        m_position.y -= (static_cast<int>(m_position.y) % 50);

    if (static_cast<int>(m_position.x) % 50 > 43)
        m_position.x += (50 - (static_cast<int>(m_position.x) % 50));

    if (static_cast<int>(m_position.y) % 50 > 43)
        m_position.y += (50 - (static_cast<int>(m_position.y) % 50));

    m_Object.setPosition(m_position);
}
//===================================================
void Robot::roundLoction()//i need to check why i need them both*
{

    // עיגול המיקום למספר הקרוב ביותר שמתחלק ב-50
    m_position.x = std::round(m_position.x / 50.0f) * 50.0f;
    m_position.y = std::round(m_position.y / 50.0f) * 50.0f;

    // עדכון המיקום של האובייקט
    m_Object.setPosition(m_position);
}
//===================checkCollision=======================
//bool Robot::checkCollision(sf::Sprite& other)
//{
//    return  m_Object.getGlobalBounds().intersects(
//           other.getGlobalBounds());
//}

sf::Sprite& Robot::getSprit()
{
    return m_Object;
}
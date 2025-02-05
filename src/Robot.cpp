#include "Robot.h"
#include <iostream>
#include <MainMenu.h>
GameControl b;
 

Robot::Robot(sf::Vector2f position,const char type)
	:MovingObject(position,type),m_point(0),m_life(5), m_firstPosition(position)
{
    m_fontLifeNum.loadFromFile("arial.ttf");
    m_textLifeNum.setCharacterSize(30);
    m_textLifeNum.setFont(m_fontLifeNum);
    m_textLifeNum.setFillColor(sf::Color::Red);
    m_textLifeNum.setString(std::to_string(m_life));
    m_textLifeNum.setPosition(80.f, 10.f);

    m_fontLifePoint.loadFromFile("arial.ttf");
    m_textLifePoint.setCharacterSize(30);
    m_textLifePoint.setFont(m_fontLifePoint);
    m_textLifePoint.setFillColor(sf::Color::White);
    m_textLifePoint.setString("Life:     Point:       Game time one minute:         Level:");
    m_textLifePoint.setPosition(20.f, 10.f);

    m_fontPoint.loadFromFile("arial.ttf");
    m_textPoint.setCharacterSize(30);
    m_textPoint.setFont(m_fontPoint);
    m_textPoint.setFillColor(sf::Color::Red);
    m_textPoint.setString(std::to_string(m_point));
    m_textPoint.setPosition(200.f, 10.f);

    m_fontLevel.loadFromFile("arial.ttf");
    m_textLevel.setCharacterSize(30);
    m_textLevel.setFont(m_fontLevel);
    m_textLevel.setFillColor(sf::Color::Red);
    m_textLevel.setString(std::to_string(GameControl::info.m_level+1));
    m_textLevel.setPosition(715.f, 10.f);

}

//====================draw============================
void Robot::draw(sf::RenderWindow& window) 
{
    window.draw(m_Object);
    window.draw(m_textLifeNum);
    window.draw(m_textLifePoint);
    window.draw(m_textPoint);
    window.draw(m_textLevel);
    
}

//==================The point=========================
void Robot::setPoint(int point)
{
	m_point += point;
    m_textPoint.setString(std::to_string(m_point));
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
    }
}

void Robot::setFirstLoc()
{
    m_position = m_firstPosition;
    m_Object.setPosition(m_firstPosition);
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

//=====================================
void Robot::setLife(int life)
{
    m_life += life;
    m_textLifeNum.setString(std::to_string(m_life));
}
//===================checkCollision=======================
//bool Robot::checkCollision(sf::Sprite& other)
//{
//    return  m_Object.getGlobalBounds().intersects(
//           other.getGlobalBounds());
//}

 //=============================================
void Robot::handleCollision(GameObject& gameObject)
{
    // double dispatch
    gameObject.handleCollision(*this);
}

//Guard
void Robot::handleCollision(Guard& gameObject)
{
    m_life-=1;
    m_Object.setPosition(m_firstPosition);
    m_textLifeNum.setString(std::to_string(m_life));
    std::cout << "kkkk \n";
    //GameControl::m_restartGame = true;
}

//Gift
void Robot::handleCollision(Gift& gameObject)
{
    //m_life++;
    m_textLifeNum.setString(std::to_string(m_life));
}
//==============================================
void Robot::handleCollision(Wall& gameObject)
{
    std::cout << "in collationWall \n";
    m_canMove = true;
}

//Rock
void Robot::handleCollision(Rock& gameObject)
{
    std::cout << "in collationRock \n";
    m_canMove = true;
}

//MovingExplod
void Robot::handleCollision(MovingExplod& gameObject)//need to check if si dead
{
    m_life-=1;
    m_textLifeNum.setString(std::to_string(m_life));
    GameControl::m_restartGame = true;
}

void Robot::handleCollision(Door& gameObject)
{
    m_point += 25;
    GameControl::info.m_level++;
    GameControl::info.m_robotPoint = m_point;
    GameControl::info.m_nextLevel = true;
    m_textPoint.setString(std::to_string(m_point));
}

//=================================================

sf::Sprite& Robot::getSprit()
{
    return m_Object;
}

 

//====================================
int Robot::getLife() 
{
    return m_life;
}
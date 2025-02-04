#include "MovingExplod.h"
#include <GameControl.h>


MovingExplod::MovingExplod(sf::Vector2f position, const char type,int direction)
    :MovingObject(roundLoction(position), type),m_direction(direction), m_countDistance(0)
{
}

void MovingExplod::move(sf::Vector2f position,float deltaTime)
{
	m_countDistance += deltaTime;

	switch (m_direction)
	{
	case 0:
		m_Object.move(0, m_moveSpeed * deltaTime);//up
		break;

	case 1:
		m_Object.move(0, -m_moveSpeed * deltaTime);//down
		break;

	case 2:
		m_Object.move(m_moveSpeed * deltaTime, 0);//right
		break;

	case 3:
		m_Object.move(-m_moveSpeed * deltaTime, 0);//left
		break;
	}
}



void MovingExplod::draw(sf::RenderWindow& window)
{
    window.draw(m_Object);
}

float MovingExplod::getDistance()  
{
	return m_countDistance;
}
//============================
sf::Vector2f MovingExplod::roundLoction(sf::Vector2f position)
{

	// עיגול המיקום למספר הקרוב ביותר שמתחלק ב-50
	position.x = std::round(position.x / 50.0f) * 50.0f;
	position.y = std::round(position.y / 50.0f) * 50.0f;

	return position;
}
void MovingExplod::ResetLocition()
{
	m_isDispose = true;
}
//============================
//collision
void MovingExplod::handleCollision(GameObject& gameObject)
{
	gameObject.handleCollision(*this);
}

//Robot
void MovingExplod::handleCollision(Robot& gameObject)
{
	if (m_Object.getGlobalBounds().intersects(gameObject.getSprit().getGlobalBounds()))
	{
		GameControl::m_restartGame = true;
		gameObject.handleCollision(*this);
		 
	}
}

//Guard
void MovingExplod::handleCollision(Guard& gameObject)
{
	if (m_Object.getGlobalBounds().intersects(gameObject.getSprit().getGlobalBounds()))
		gameObject.handleCollision(*this);
}

//Wall
void MovingExplod::handleCollision(Wall& gameObject)
{
}
//=========================================

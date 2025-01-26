#include "MovingExplod.h"

MovingExplod::MovingExplod(sf::Vector2f position, const char type,int direction)
    :MovingObject(position, type),m_direction(direction), m_countDistaance(0)
{
}

void MovingExplod::move(float deltaTime)
{
	m_countDistaance += deltaTime;

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

float MovingExplod::getDistaance()
{
	return m_countDistaance;
}

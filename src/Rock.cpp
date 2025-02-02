#include "Rock.h"

Rock::Rock(sf::Vector2f position, const char type)
	:GameObject(position, type)
{
}
 

void Rock::draw(sf::RenderWindow& window)
{
	window.draw(m_Object);
}

//Robot
void Rock::handleCollision(Robot& gameObject)
{
	if (m_Object.getGlobalBounds().intersects(gameObject.getSprit().getGlobalBounds()))
		gameObject.handleCollision(*this);

	return;
}

//Guard
void Rock::handleCollision(Guard& gameObject)
{
	if (m_Object.getGlobalBounds().intersects(gameObject.getSprit().getGlobalBounds()))
		gameObject.handleCollision(*this);

	return;
}

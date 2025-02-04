#include "Gift.h"

Gift::Gift(sf::Vector2f position, const char type)
	:GameObject(position, type)
{
}

 
sf::Sprite& Gift::getSprit()
{
	return m_Object; // החזרת הספירייט של האובייקט
}

void Gift::draw(sf::RenderWindow& window)
{
	window.draw(m_Object);
}

//Robot
void Gift::handleCollision(Robot& gameObject)
{
	if (m_Object.getGlobalBounds().intersects(gameObject.getSprit().getGlobalBounds()))
	{
		m_isDispose = true;
		//gameObject.handleCollision(*this);
	}

	return;
}

#include "Gift.h"

Gift::Gift(sf::Vector2f position, const char type)
	:GameObject(position, type)
{
}

sf::Sprite& Gift::gatSprite()
{
	return m_Object;
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
		gameObject.handleCollision(*this);

	}

	return;
}

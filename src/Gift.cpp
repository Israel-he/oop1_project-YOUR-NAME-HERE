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
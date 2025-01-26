#include "Door.h"

Door::Door(sf::Vector2f position, const char type)
	:GameObject(position, type)
{
}

sf::Sprite& Door::gatSprite()
{
	return m_Object;
}


void Door::draw(sf::RenderWindow& window)
{
	window.draw(m_Object);
}

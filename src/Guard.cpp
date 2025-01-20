#include "Guard.h"

Guard::Guard(sf::Vector2f position, const char type)
	:GameObject(position, type)
{
}

void Guard::draw(sf::RenderWindow& window)
{
	window.draw(m_Object);
}

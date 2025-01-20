#include "Rock.h"

Rock::Rock(sf::Vector2f position, const char type)
	:GameObject(position, type)
{
}

void Rock::draw(sf::RenderWindow& window)
{
	window.draw(m_Object);
}

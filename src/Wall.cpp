#include "Wall.h"

Wall::Wall(sf::Vector2f position, const char type)
	:GameObject(position, type)
{
}

 

void Wall::draw(sf::RenderWindow& window)
{
	window.draw(m_Object);
}

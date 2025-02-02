#include "Wall.h"

Wall::Wall(sf::Vector2f position, const char type)
	:GameObject(position, type)
{
}

void Wall::draw(sf::RenderWindow& window)
{
	window.draw(m_Object);
}
 
//=========================================
bool Wall::getIsdispose()
{
	return m_isDispose;
}
//====================Robot======================
void Wall::handleCollision(Robot& gameObject)
{
   if(m_Object.getGlobalBounds().intersects(gameObject.getSprit().getGlobalBounds()))
	 gameObject.handleCollision(*this);

   return;
}
//=============================================

//===================Guard======================
void Wall::handleCollision(Guard& gameObject)
{
	if (m_Object.getGlobalBounds().intersects(gameObject.getSprit().getGlobalBounds()))
		gameObject.handleCollision(*this);

	return;
}
//=========================MovingExplod======================
void Wall::handleCollision(MovingExplod& gameObject)
{
	if (m_Object.getGlobalBounds().intersects(gameObject.getSprit().getGlobalBounds()))
		m_isDispose = true;

	return;
}



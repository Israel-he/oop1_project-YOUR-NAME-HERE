#pragma once
#include <SFML/Graphics.hpp>
#include "GameObject.h"

class MovingObject: public GameObject
{   
public:
	MovingObject(sf::Vector2f position, const char type);

	//virtual void move(float l) = 0;

	 sf::Vector2f getPosition();


protected:
	sf::Vector2f m_direction;
};
 
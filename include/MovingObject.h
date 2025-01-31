#pragma once
#include <SFML/Graphics.hpp>
#include "GameObject.h"

class MovingObject: public GameObject
{   
public:
	MovingObject(sf::Vector2f position, const char type);
	virtual void move(sf::Vector2f position,float deltaTime) = 0;
	//virtual void move(float l) = 0;
	
	 sf::Vector2f getPosition() const;
	 virtual float getDistance() ;

protected:
	sf::Vector2f m_direction;
};
 
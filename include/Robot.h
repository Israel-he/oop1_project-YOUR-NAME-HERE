#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Network.hpp>
 
#include "MovingObject.h"

class Robot :public  MovingObject
{
public:
    Robot(sf::Vector2f position,const char type);

	virtual void draw(sf::RenderWindow& window) override;

	//virtual sf::Sprite& gatSprite() override;
   // bool checkCollision(sf::Sprite& other);


	void move(float m_deltaTime);
    
	//point==================
	void setPoint(int point);
	int getPoint();
	//=======================
	
	//position=================
	void setPosition(sf::Vector2f position);
	sf::Vector2f getPosition();
	//=========================
	
	//captuareLocition
	void captuareLocition();//move the robot to the (% 50)

	void resetClock();

  
private:

	int m_life;
	int m_point;
	const float moveSpeed = 150.f;
};

 
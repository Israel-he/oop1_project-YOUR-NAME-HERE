#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Network.hpp>
 
#include "GameObject.h"

class Robot :public GameObject
{
public:
    Robot(sf::Vector2f position,const char type);

	virtual void draw(sf::RenderWindow& window) override;

	void move(sf::Event& event, float m_deltaTime);

	//point==================
	void setPoint(int point);
	int getPoint();
	//=======================
	
	//position=================
	void setPosition(sf::Vector2f position);
	sf::Vector2f getPosition();
	//=========================

	void resetClock();

	 
private:

	sf::Clock m_time;
	int m_point;
	sf::Event m_event;
	const float moveSpeed = 150.f;
};

 
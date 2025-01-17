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
	//virtual void draw(sf::RenderWindow& window) override;

private:

	//sf::Vector2f m_position;

	sf::Clock m_time;

	int m_point;

	sf::Event m_event;

	//sf::Texture m_TxtRobot;
	//sf::Sprite m_robot;

   //The speed and time of the robot
   const float moveSpeed = 100.f;
};

 
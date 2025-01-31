#pragma once
#include <SFML/Graphics.hpp>
#include "MovingObject.h"
#include "Wall.h"

class Robot :public MovingObject
{
public:
	Robot(sf::Vector2f position, const char type);
	sf::Sprite& getSprit();
	virtual void draw(sf::RenderWindow& window) override;

	//virtual sf::Sprite& gatSprite() override;
   // bool checkCollision(sf::Sprite& other);



	void move(sf::Vector2f position, float deltaTime) override;


	//captuareLocition
	void captuareLocition();//move the robot to the (% 50)


	//point==================
	void setPoint(int point);
	int getPoint();
	//=======================

	//position=================
	void setPosition(sf::Vector2f position);
	sf::Vector2f getPosition();
	//=========================
	void roundLoction();

	//check collisions
	//bool checkCollision(float deltaTime);
	virtual void handleCollision(GameObject& gameObject);
	virtual void handleCollision(Robot& gameObject) {};
	virtual void handleCollision(Guard& gameObject) {};
	virtual void handleCollision(Gift& gameObject) {};
	virtual void handleCollision(Wall& gameObject) ;//
	virtual void handleCollision(Rock& gameObject) ;
	virtual void handleCollision(Bomb& gameObject) {};
	virtual void handleCollision(MovingExplod& gameObject) {};
	virtual void handleCollision(Door& gameObject) {};

private:
	bool m_canMove = false;
	int m_life;
	int m_point;
	const float moveSpeed = 150.f;

	sf::Font m_fontLifeNum;
	sf::Text m_textLifeNum;

	sf::Font m_fontLife;
	sf::Text m_textLife;
};


/*///////////////////////////////////////
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


void move(float m_deltaTime, const std::vector<std::unique_ptr<GameObject>>& objects);
   
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

sf::FloatRect getGlobalBoundsForNewPosition(const sf::Vector2f& newPosition) const;
 
private:

int m_life;
int m_point;
const float moveSpeed = 150.f;
};*/
#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Network.hpp>

#include "LoadTexture.h"
class Robot;
class Guard;
class Door;
class Wall;
class Rock;
class Bomb;
class MovingExplod;
class Gift;

class GameObject //:private LoadTexture
{
public:

	GameObject(const sf::Vector2f& pos,const char type);
	virtual ~GameObject() {};
	virtual void draw(sf::RenderWindow& window) = 0;
	 
    sf::Sprite& getSprit();
    sf::Sprite& getSprit() const;
	//get and set positions=====================
	void setPosition(const sf::Vector2f& newPos);
    sf::Vector2f getPosition() const;
	//==========================================
	//virtual sf::Sprite& gatSprite();

	//virtual float getDistance();

	//checking collisions
	bool checkCollision(const GameObject& other) const;
	
	virtual void handleCollision(GameObject& gameObject) = 0;
	virtual void handleCollision(Robot& gameObject) = 0;
	virtual void handleCollision(Guard& gameObject) = 0;
	virtual void handleCollision(Gift& gameObject) = 0;
	virtual void handleCollision(Wall& gameObject) = 0;
	virtual void handleCollision(Rock& gameObject) = 0;
	virtual void handleCollision(Bomb& gameObject) = 0;
	virtual void handleCollision(MovingExplod& gameObject) = 0;
	virtual void handleCollision(Door& gameObject) = 0;
	bool getIsdispose();
protected:
	
	sf::Vector2f m_position;
	sf::Sprite m_Object;
	bool m_isDispose = false;

private:
	LoadTexture m_loadTexture;
};

#pragma once
#include <SFML/Graphics.hpp>

#include "MovingObject.h"
#include "Guard.h"

class MovingExplod :public MovingObject
{
public:
	MovingExplod(sf::Vector2f position, const char type, int direction);

	//void move(sf::Vector2f position,float deltaTime)override;

	virtual void draw(sf::RenderWindow& window) override;

    float getDistance();
	void move(sf::Vector2f position, float deltaTime);
	sf::Vector2f roundLoction(sf::Vector2f position);
	virtual void ResetLocition() override;
	virtual bool getIsdispose();

	//check collisions
	//bool checkCollision(float deltaTime);
	virtual void handleCollision(GameObject& gameObject) ;
	virtual void handleCollision(Robot& gameObject);
	virtual void handleCollision(Guard& gameObject);
	virtual void handleCollision(Gift& gameObject) {};
	virtual void handleCollision(Wall& gameObject);
	virtual void handleCollision(Rock& gameObject) {};
	virtual void handleCollision(Bomb& gameObject) {};
	virtual void handleCollision(MovingExplod& gameObject) {};
	virtual void handleCollision(Door& gameObject) {};
private:
	int m_direction;
	float m_moveSpeed = 100.f;
	float m_countDistance;//sum 50 pixsel anden delete
};
#pragma once
#include "GameObject.h"
#include "Robot.h"
#include "Guard.h"
#include "MovingExplod.h"

class Wall :public GameObject
{
public:

	Wall(sf::Vector2f position, const char type);

 
	//virtual void handleCollision(Robot& gameObject);
	virtual void draw(sf::RenderWindow& window) override;
	bool getIsdispose();

	//check collisions
	//bool checkCollision(float deltaTime);
	virtual void handleCollision(GameObject& gameObject) {};
	virtual void handleCollision(Robot& gameObject);
	virtual void handleCollision(Guard& gameObject);
	virtual void handleCollision(Gift& gameObject) {};
	virtual void handleCollision(Wall& gameObject) {};//
	virtual void handleCollision(Rock& gameObject) {};
	virtual void handleCollision(Bomb& gameObject) {};
	virtual void handleCollision(MovingExplod& gameObject);
	virtual void handleCollision(Door& gameObject) {};
private:


};
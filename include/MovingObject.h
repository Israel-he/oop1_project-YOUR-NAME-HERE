#pragma once
#include <SFML/Graphics.hpp>
#include "GameObject.h"

class MovingObject : public GameObject
{
public:
	MovingObject(sf::Vector2f position, const char type);
	virtual void move(sf::Vector2f position, float deltaTime) = 0;
	//virtual void move(float l) = 0;

	sf::Vector2f getPosition() const;
	virtual float getDistance();
	virtual void setPoint(int point);

	virtual void setFirstLoc();

	virtual bool Frozen() const; // הצהרה על הפונקציה Frozen
	virtual void setfreezeDuration(int deltaTime) ;
	virtual bool getFreezeDuration() ;
    virtual bool isFrozen() const ;
	virtual void ResetLocition();
	virtual void setLife(int life); // Add this line
	virtual void moveTowards(sf::Vector2f target, float deltaTime, std::vector<std::unique_ptr<GameObject>>& objects) {};
	virtual int getLife();
protected:
	sf::Vector2f m_firstPosition;
	sf::Vector2f m_direction;
	bool m_frozen = false; 
	int m_freezeDuration = 0;
};
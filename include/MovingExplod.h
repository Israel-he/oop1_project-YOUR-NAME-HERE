#pragma once
#include <SFML/Graphics.hpp>

#include "MovingObject.h"


class MovingExplod :public MovingObject
{
public:
	MovingExplod(sf::Vector2f position, const char type, int direction);

	void move(float deltaTime);

	virtual void draw(sf::RenderWindow& window) override;

	float getDistaance();
private:
	int m_direction;
	float m_moveSpeed = 100.f;
	float m_countDistaance;//sum 50 pixsel anden delete
};
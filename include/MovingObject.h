#include <SFML/Graphics.hpp>

class  MovingObject
{   
public:
	MovingObject();

	virtual void move() = 0;

	void setPosition(sf::Vector2f position);
	sf::Vector2f getPosition();


private:

	sf::Clock m_clock;
	sf::Vector2f m_position;
};
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Network.hpp>

#include "LoadTexture.h"

class GameObject :public LoadTexture
{
public:

	GameObject(const sf::Vector2f& pos,const char type);

	//get and set positions=====================
	void setPosition(const sf::Vector2f& newPos);
	sf::Vector2f getPosition() const;
	//==========================================

	bool checkCollision(const GameObject& other) const;

	 virtual void draw(sf::RenderWindow& window);

protected:

	sf::Vector2f m_position;
	sf::Sprite m_Object;
};

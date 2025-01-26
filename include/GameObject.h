#pragma once
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

	virtual void draw(sf::RenderWindow& window) = 0;

	
	//get and set positions=====================
	void setPosition(const sf::Vector2f& newPos);
	sf::Vector2f getPosition() const;
	//==========================================
	//virtual sf::Sprite& gatSprite();

protected:

	sf::Vector2f m_position;
	sf::Sprite m_Object;
};

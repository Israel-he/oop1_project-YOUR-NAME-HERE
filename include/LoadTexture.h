#pragma once
 
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Network.hpp>

class LaodTexture
{
public:
	LaodTexture();
   

    class LoadTexture
    {
    public:
        sf::Texture& getTexture(char symbol);
    };
	sf::Texture& getTexture(const char symbol);
private:

	sf::Texture m_robot;
	sf::Texture m_guard;
	sf::Texture m_Wall; 
	sf::Texture m_rock;
	sf::Texture m_door;
  
};
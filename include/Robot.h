
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Network.hpp>
 
#include "LoadTexture.h"
class Robot
{
public:
    Robot();

private:

	sf::Sprite m_robot;
	char m_symbol;
};
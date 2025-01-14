#include "LoadTexture.h"

LaodTexture::LaodTexture()
{
	m_robot.loadFromFile("robot.jpg");
	m_guard.loadFromFile("guard.jpg");
	m_rock.loadFromFile("rock.jpg");
	m_Wall.loadFromFile("wall.jpg"); 
	m_door.loadFromFile("door.jpg");
}

sf::Texture& LaodTexture::getTexture(const char symbol)
{
    switch (symbol)
    {
    case '/':
        return m_robot;
        break;
    case '!':
        return m_guard;
        break;
    case 'D':
        return m_door;
        break;
    case '#':
        return m_Wall;
        break;
    case '@':
        return m_rock;
        break;
    }
}

#include "LoadTexture.h"

LoadTexture::LoadTexture()
{
	m_robot.loadFromFile("robot.jpg");
	m_guard.loadFromFile("guard.jpg");
	m_rock.loadFromFile("rock.jpg");
	m_Wall.loadFromFile("wall.jpg"); 
	m_door.loadFromFile("door.jpg");
    m_bomb.loadFromFile("bomb.png");
    m_explosion_up.loadFromFile("explosion_up.jpg");
    m_explosion_down.loadFromFile("explosion_down.jpg");
    m_explosion_right.loadFromFile("explosion_right.jpg");
    m_explosion_left.loadFromFile("explosion_left.jpg");
    m_explosion.loadFromFile("explosion.jpg");
}

sf::Texture& LoadTexture::getTexture(const char symbol)
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
    case 'b':
        return m_bomb;
        break;
    case 'e':
        return m_explosion;
        break;
    }
}

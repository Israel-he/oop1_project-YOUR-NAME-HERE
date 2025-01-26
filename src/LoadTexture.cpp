#include "LoadTexture.h"
#include "io.h"
#include <iostream>
LoadTexture::LoadTexture()
{
    std::cout << "in ctor load \n";
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
    m_life.loadFromFile("life.png");
}

sf::Texture& LoadTexture::getTexture(const char symbol)
{
    switch (symbol)
    {
    case ID::ROBOT:
        return m_robot;
        break;
    case ID::GUARD:
        return m_guard;
        break;
    case ID::DOOR:
        return m_door;
        break;
    case ID::WALL:
        return m_Wall;
        break;
    case ID::ROCK:
        return m_rock;
        break;
    case ID::BOMB:
        return m_bomb;
        break;
    case ID::BOMB_explode:
        return m_explosion;
        break;
    case ID::LIFE:
        return m_life;
        break;
    }
}

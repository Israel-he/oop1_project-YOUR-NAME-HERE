#include "WindowGame.h"
 

WindowGame::WindowGame(unsigned int cols, unsigned int rows)
    :Window(cols, rows),m_position(50.f,50.f)
{
    m_robot.loadFromFile("robot.jpg");
     
    m_robotSprite.setTexture(m_robot);
    m_robotSprite.setPosition(m_position);
}

void WindowGame::drawWindowGame()
{
    m_window.clear(sf::Color::Blue);
    m_window.draw(m_robotSprite);
     
    m_window.display();
}

void WindowGame::move()
{
    for(int i=0;i<20;i++)
    m_robotSprite.move(0.f, 1.f);
}
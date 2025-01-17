#include "GameControl.h"

//c_tor
GameControl::GameControl()
	:m_position(50.f, 50.f),m_robot(new Robot(m_position,'/'))
{
	m_videoMode.height = 800;
	m_videoMode.width = 800;

	iniwindow();
}

//d_tor
GameControl::~GameControl()
{
	delete m_robot;
}

//====================window====================
void GameControl::iniwindow()
{
	m_window.create(m_videoMode, "My first game", sf::Style::Titlebar | sf::Style::Close);
}

//===============================================
bool GameControl::windowIsOpen() const
{
	return m_window.isOpen();
}
//==================update==========================

void GameControl::update()
{
	pollEvent();
}
//===================render==========================
void GameControl::render()
{
	m_window.clear(sf::Color::Black);
	m_robot->draw(m_window);
	m_window.display();
}
//===================pollEvevt=========================
void GameControl::pollEvent()
{
	m_deltaTime = m_clock.restart().asSeconds();

	m_window.pollEvent(m_event);
	{
		switch (m_event.type)
		{
		case sf::Event::Closed:
			m_window.close();
			break;

		case sf::Event::KeyPressed:
			m_robot->move(m_event, m_deltaTime);
			break;

		}
		
	}
}
//===========================================


#include "GameControl.h"
#include <iostream>
using namespace std;
//c_tor
GameControl::GameControl()
	:m_position(0.f, 0.f), m_robot(nullptr),
	inputFile("Board.txt"), m_videoMode(800, 800)
{
	iniwindow();
	readFile();
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

//====================CheckIfFileOpen==============
bool GameControl::windowIsOpen() const
{
	return m_window.isOpen();
}

//==================ReadFile========================
void GameControl::readFile()
{
	char ObjType;
	int row = 0, col = 0;
	while (inputFile.get(ObjType))
	{
		if (ObjType == '\n')
		{
			row++;
			col = 0;
		}
		else
		{
			switchObject(ObjType, getLoc(row, col));
			col++;
		}
	}
	inputFile.close();
}

void GameControl::switchObject(const char symbol, sf::Vector2f locition)
{
	switch (symbol)
	{
	case '/':
		m_robot = new Robot(locition, '/');
		break;
	case '!':
		return m_objects.push_back(std::make_unique<Guard>(locition, symbol));
		break;
	case 'D':
		return m_objects.push_back(std::make_unique<Door>(locition, symbol));
		break;
	case '#':
		m_objects.push_back(std::make_unique<Wall>(locition, symbol));
		break;
	case '@':
		return m_objects.push_back(std::make_unique<Rock>(locition, symbol));
		break;
	}
}
//====================================================
sf::Vector2f GameControl::getLoc(int row, int col)//?need to do &?
{
	row = (row * 50);
	col = (col * 50);
	return sf::Vector2f(col, row);
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
	 
	for (int i = 0; i < m_objects.size();i++) 
	{
		m_objects[i]->draw(m_window);
	}
	 
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


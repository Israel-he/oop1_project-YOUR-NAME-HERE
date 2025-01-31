#include "GameControl.h"
#include <iostream>
using namespace std;

//c_tor
GameControl::GameControl()
	:inputFile("Board.txt"), m_videoMode(800, 800)
{
	iniwindow();
	readFile();

	m_fontTimerp.loadFromFile("arial.ttf");
	m_TextTimep.setCharacterSize(30);
	m_TextTimep.setFont(m_fontTimerp);
	m_TextTimep.setFillColor(sf::Color::Red);
	m_TextTimep.setPosition(20.f,40.f);
	 
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
	case ID::ROBOT:
		m_robot = std::make_unique<Robot>(locition, ID::ROBOT);
		break;
	case ID::GUARD:
		m_guard.push_back(std::make_unique<Guard>(locition, ID::GUARD));
		break;
	case ID::DOOR:
		m_objects.push_back(std::make_unique<Door>(locition, ID::DOOR));
		break;
	case ID::WALL:
		m_objects.push_back(std::make_unique<Wall>(locition, ID::WALL));
		break;
	case ID::ROCK:
		m_objects.push_back(std::make_unique<Rock>(locition, ID::ROCK));
		break;
	case ID::BOMB:
		m_objects.push_back(std::make_unique<Bomb>(locition, ID::BOMB));
		break;
	case ID::LIFE:
		m_objects.push_back(std::make_unique<Gift>(locition, ID::LIFE));
		m_objects.push_back(std::make_unique<Wall>(locition, ID::WALL));
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
	run();
}
//=======================srtTimer=============================
void GameControl::setTimer(float time)
{
	m_countTime += m_deltaTime;
	if (m_countTime >= 1 )
	{
		count++;
		m_TextTimep.setString(std::to_string(count));
		m_countTime = 0;
	}
		

}
//====================draw===========================
void GameControl::draw()
{
	//robot
	m_robot->draw(m_window);

	 //guards
	for (int i = 0; i < m_guard.size(); i++)
	{
		m_guard[i]->draw(m_window);
	}

	//unMoveObjects
	for (int i = 0; i < m_objects.size(); i++)
	{
		m_objects[i]->draw(m_window);
	}

	//bombs
	for (int i = 0; i < m_bomb.size(); i++)
	{
		m_bomb[i]->draw(m_window);
	}

	//moving bombs
	for (int i = 0; i < m_MovingExplod.size(); i++)
	{
		m_MovingExplod[i]->draw(m_window);
	}
	m_window.draw(m_TextTimep);
}
//====================checkCollision========================
void GameControl::checkCollision(GameObject& gameObject)
{
	for (auto& unmovable : m_objects)
	{
		gameObject.handleCollision(*unmovable);
	}
}
//======================run===========================
void GameControl::run()
{
	m_deltaTime = m_clock.restart().asSeconds();
	setTimer(m_deltaTime);
	m_robot->move(m_position,m_deltaTime);// m_position no reaason
	checkCollision(*m_robot);
	for (int i = 0; i < m_guard.size(); i++)
	{
		m_guard[i]->move(m_robot->getPosition(), m_deltaTime);
		checkCollision(*m_guard[i]);
	}

	for (int i = 0; i < m_bomb.size(); i++)
	{
		if (m_bomb[i]->getCountDown() < 0)
		{
			creatMoveExplod(m_bomb[i]->getPosition());
			m_bomb.erase(m_bomb.begin() + i);
		}
		else
			m_bomb[i]->countTime(m_deltaTime);
	}

	for (int i = 0; i < m_MovingExplod.size(); i++)
	{
		if (m_MovingExplod[i]->getDistance() >= 0.45)
			m_MovingExplod.erase(m_MovingExplod.begin() +i);
		else
		{
			m_MovingExplod[i]->move(m_position, m_deltaTime);//m_position no reaason
			checkCollision(*m_MovingExplod[i]);
		}
	}
		std::erase_if(m_objects, [](auto& object)
			{
				return object->getIsdispose();
			});
		
}
//==============create moving expload==================
void GameControl::creatMoveExplod(sf::Vector2f position)
{
	for (int i = 0; i < 4; i++)
	{
		m_MovingExplod.push_back((std::make_unique<MovingExplod>(position, ID::BOMB_explode, i)));
	}
}

//===================render==========================
void GameControl::render()
{
	m_window.clear(sf::Color::Black);
	draw();
	m_window.display();
}


//===================pollEvevt========================
void GameControl::pollEvent()
{
	m_window.pollEvent(m_event);
	{
		switch (m_event.type)
		{
		case sf::Event::Closed:
			m_window.close();
			break;

		case sf::Event::KeyPressed:
			if (m_event.key.code == sf::Keyboard::B)
				m_bomb.push_back(std::make_unique<Bomb>(m_robot->getPosition(),ID::BOMB));
			break;
		}
	}
}

#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Network.hpp>

#include <memory>
#include <iostream>
#include <fstream>
 
#include "io.h"
#include "Robot.h"
#include "Wall.h"
#include "Rock.h"
#include "Door.h"
#include "Guard.h"
#include "Bomb.h"
#include "Gift.h"
#include "MovingExplod.h"

class GameControl
{
public:

	//C-tor & D-tor
	GameControl();
	 
	//============================
	//functions for the Window
	//Check if the window is open
	bool windowIsOpen()const;
	void iniwindow();
	//===========================

	//Read the file
	void readFile();
	void switchObject(const char symbol, sf::Vector2f locition);
	sf::Vector2f getLoc(int row, int col);

	//Incharg on the events
	void pollEvent();

	//Update the game
	void update();
	//Render the game
	void render();

	void run();

	//draw
	void draw();
	
	void creatMoveExplod(sf::Vector2f position);
private:

	sf::RenderWindow m_window;
	sf::VideoMode m_videoMode;

	//ReadFile
	std::ifstream inputFile;

	sf::Event m_event;

	//clock
	sf::Clock m_clock;
	float m_deltaTime;

	//Moving objects
	 
	std::unique_ptr<Robot> m_robot;
	std::vector<std::unique_ptr<Guard>> m_guard;
	std::vector<std::unique_ptr<MovingExplod>> m_MovingExplod;

	//unMoving objects
	std::vector<std::unique_ptr<GameObject>> m_objects;
	std::vector<std::unique_ptr<Bomb>> m_bomb;
	std::vector<std::unique_ptr<Gift>> m_gift;
};
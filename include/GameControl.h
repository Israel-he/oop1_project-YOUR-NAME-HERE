#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Network.hpp>

#include <memory>
#include <iostream>
#include <fstream>
 
#include "Robot.h"
#include "Wall.h"
#include "Rock.h"
#include "Door.h"
#include "Guard.h"


class GameControl
{
public:

	//C-tor & D-tor
	GameControl();
	~GameControl();

	//============================
	//functions for the Window
	//Check if the window is open
	bool windowIsOpen()const;
	void iniwindow();
	//===========================
			
	//Incharg on the events
	void pollEvent();

//////////////////////
	//Update the game
	void update();
	//Render the game
	void render();
/////////////////////

	//Read the file
	void readFile();
	void switchObject(const char symbol, sf::Vector2f locition);
	sf::Vector2f getLoc(int row, int col);

private:

	sf::RenderWindow m_window;
	sf::VideoMode m_videoMode;

	//ReadFile
	//std::ifstream inputFile;
	std::ifstream inputFile;
	sf::Event m_event;

	sf::Vector2f m_position;

	//clock
	sf::Clock m_clock;
	float m_deltaTime;

	//Moving objects
	Robot* m_robot;
	std::vector<std::unique_ptr<GameObject>> m_objects;
};



/*	WindowGame m_WindowGame;
 
	//size of window
	sf::VideoMode m_videoMode;

	sf::Event m_event;
	sf::Texture m_robot;
	//The guards of the game
	//std::vector<Guard*> m_guard;To ues 

	//The gifts of the game
	//std::vector<Gift*> m_gift;To ues &gift1

	//The static objects in the game
	//std::vector<?> m_object

	sf::Clock m_clock;*/
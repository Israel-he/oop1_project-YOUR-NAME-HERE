#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Network.hpp>
#include <WindowGame.h>
class GameControl
{
public:

	//Constractor
	GameControl();

	//============================
	//functions for the WindowGame
	 
	//Check if the window is open
	bool windowIsOpen()const;
	void run(WindowGame& WindowGame);

	//Incharg on the events
	void pollEvent();

	//Update the game
	void upDate();

	//Render the game
	void render();


private:

	WindowGame m_WindowGame;
 
	//size of window
	sf::VideoMode m_videoMode;

	sf::Event m_event;

	//The guards of the game
	//std::vector<Guard*> m_guard;To ues 

	//The gifts of the game
	//std::vector<Gift*> m_gift;To ues &gift1

	//The static objects in the game
	//std::vector<?> m_object

	sf::Clock m_clock;

};
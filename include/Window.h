#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Network.hpp>

class Window
{
public:
	Window(unsigned int cols = 800, unsigned int rows = 800);

	const bool windowisOpen() const; // Fix typo in method name

	void createWindow();

	//create the sprite to  both move and not mode pic
	sf::Sprite create(sf::Texture& pic,sf::Vector2f position);

protected:
	sf::RenderWindow m_window;

	// size of window
	sf::VideoMode m_videoMode;

};
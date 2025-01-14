#include "Window.h"

class WindowGame :public Window
{
public:
	WindowGame(unsigned int cols = 800, unsigned int rows = 800);

	void move();

	void drawWindowGame();

private:
	sf::Texture m_robot;
	sf::Sprite  m_robotSprite;
	sf::Vector2f m_position;
};
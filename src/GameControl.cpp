#include "GameControl.h"

GameControl::GameControl()
         :m_event(), m_videoMode(), m_clock(), m_WindowGame() // Initialize m_WindowGame here
{
}

bool GameControl::windowIsOpen() const
{
	return m_WindowGame.windowisOpen();
}

//uplode the WindoeGame
void GameControl::run(WindowGame& WindowGame)
{
	WindowGame.drawWindowGame();
}

void GameControl::render()
{
	run(m_WindowGame);
}

#include "Bomb.h"
#include "string"
Bomb::Bomb(sf::Vector2f position, const char type)
     :GameObject(position,type),m_countSec(0)
{
	m_fontTimer.loadFromFile("arial.ttf");
	m_textTime.setCharacterSize(24);
	m_textTime.setFont(m_fontTimer);
	m_textTime.setFillColor(sf::Color::Red);
}
//===============draw======================
void Bomb::draw(sf::RenderWindow& window)
{
	window.draw(m_Object);
	window.draw(m_textTime);
}

//=====================countDownTimer===================
void Bomb::countTime(float deltaTime)
{
	m_countSec += deltaTime;
	if (m_countSec >= 1)
	{
		m_textTime.setString(std::to_string(m_countDown));
		m_textTime.setPosition(m_position.x+20.f, m_position.y + 10.f);
		m_countDown--;
		m_countSec = 0;
	}
}

//===============================
int Bomb::getCountDown()const
{
	return m_countDown;
}

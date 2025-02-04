#include "Timer.h"

Timer::Timer()
	
{
	//second
	m_fontSecond.loadFromFile("arial.ttf");
	m_TextSecond.setCharacterSize(30);
	m_TextSecond.setFont(m_fontSecond);
	m_TextSecond.setFillColor(sf::Color::Red);
	m_TextSecond.setPosition(600.f, 10.f);

	m_fontChar.loadFromFile("arial.ttf");
	m_TextChar.setCharacterSize(30);
	m_TextChar.setFont(m_fontChar);
	m_TextChar.setFillColor(sf::Color::Red);
	m_TextChar.setPosition(585.f, 10.f);
	m_TextChar.setString(":");

	//minute
	m_fontMinute.loadFromFile("arial.ttf");
	m_TextMinute.setCharacterSize(30);
	m_TextMinute.setFont(m_fontMinute);
	m_TextMinute.setFillColor(sf::Color::Red);
	m_TextMinute.setPosition(565.f, 10.f);
	m_TextMinute.setString(std::to_string(m_countMinute));

	
}

void Timer::updateTime(float time)
{
	m_count += time;

	if (m_count >= 1)
	{
		m_countSecond++;
		m_count = 0;
		m_TextSecond.setString(std::to_string(m_countSecond));

	}
	if (m_countSecond >= 59)
	{
		m_countMinute++;
		m_countSecond = 0;
		m_TextMinute.setString(std::to_string(m_countMinute));

	}
}

void Timer::draw(sf::RenderWindow& window)
{
	window.draw(m_TextSecond);
	window.draw(m_TextMinute);
	window.draw(m_TextChar);
}

int Timer::getMinute()
{
	return m_countMinute;
}

void Timer::addTime(int num)
{
	m_countSecond -= num;
	if (m_countSecond < 0)
		m_countSecond = 0;
}

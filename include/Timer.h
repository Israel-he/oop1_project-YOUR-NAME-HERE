#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/Graphics/Font.hpp>
#include <SFML/Graphics/Text.hpp> 
#include <SFML/System/Export.hpp>
#include <SFML/System/Utf.hpp>
#include <iterator>
#include <locale> // Add this line
#include <string>
#include <iostream>
class Timer
{
public:
	Timer();

	void updateTime(float time);
	void draw(sf::RenderWindow& window);



private:
	int m_countSecond = 0;
	int m_countMinute = 0;
	float m_count = 0;

	sf::Font m_fontSecond;
	sf::Text m_TextSecond;

	sf::Font m_fontMinute;
	sf::Text m_TextMinute;

	sf::Font m_fontChar;
	sf::Text m_TextChar;
};
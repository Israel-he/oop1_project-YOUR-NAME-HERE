#include "GameObject.h"

class Bomb :public GameObject
{
public:
	Bomb(sf::Vector2f position, const char type);

	virtual void draw(sf::RenderWindow& window) override;
	void countTime(float deltaTime);
	int getCountDown() const;
private:

	double m_countSec;
	int m_countDown = 5;

	sf::Font m_fontTimer;
	sf::Text m_textTime;
};
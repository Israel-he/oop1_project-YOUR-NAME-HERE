#include "GameObject.h"

class Bomb :public GameObject
{
public:
	Bomb(sf::Vector2f position, const char type);

	virtual void draw(sf::RenderWindow& window) override;
	void countTime(float deltaTime);
	int getCountDown() const;
	bool getIsdispose();
	void resetLocation();

	//check collisions
	bool checkCollision(float deltaTime);
	virtual void handleCollision(GameObject& gameObject) {};
	virtual void handleCollision(Robot& gameObject) {};
	virtual void handleCollision(Guard& gameObject) {};
	virtual void handleCollision(Gift& gameObject) {};
	virtual void handleCollision(Wall& gameObject) {};//
	virtual void handleCollision(Rock& gameObject) {};
	virtual void handleCollision(Bomb& gameObject) {};
	virtual void handleCollision(MovingExplod& gameObject) {};
	virtual void handleCollision(Door& gameObject) {};
private:

	double m_countSec;
	int m_countDown = 3;

	sf::Font m_fontTimer;
	sf::Text m_textTime;
};
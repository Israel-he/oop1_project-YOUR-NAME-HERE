#include "GameObject.h"

class Wall :public GameObject
{
public:

	Wall(sf::Vector2f position, const char type);

	virtual void draw(sf::RenderWindow& window) override;

private:


};
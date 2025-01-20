#include "GameObject.h"

class Rock :public GameObject
{
public:

	Rock(sf::Vector2f position, const char type);

	virtual void draw(sf::RenderWindow& window) override;

private:


};
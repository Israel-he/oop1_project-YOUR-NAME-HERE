#include "GameObject.h"

class Guard :public GameObject
{
public:

	Guard(sf::Vector2f position, const char type);

	virtual void draw(sf::RenderWindow& window) override;

private:
};
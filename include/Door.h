#include "GameObject.h"

class Door :public GameObject
{
public:

	Door(sf::Vector2f position, const char type);

	virtual sf::Sprite& gatSprite();
	

	virtual void draw(sf::RenderWindow& window) override;

private:
};
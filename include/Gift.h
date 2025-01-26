#include "GameObject.h"

class Gift :public GameObject
{
public:

	Gift(sf::Vector2f position, const char type);

	virtual sf::Sprite& gatSprite();


	virtual void draw(sf::RenderWindow& window) override;

private:
};













//need to fix rondom guard


#include "Guard.h"
#include <iostream>
// Constructor
Guard::Guard(sf::Vector2f position, const char type)
    :MovingObject(position, type), frozen(false), freezeDuration(0)
{
    randomOffset.x = static_cast<float>(rand() % 101 - 50) / 50.0f * randomnessFactor;
    randomOffset.y = static_cast<float>(rand() % 101 - 50) / 50.0f * randomnessFactor;
    uniqueOffset.x = static_cast<float>(rand() % 201 - 100);
    uniqueOffset.y = static_cast<float>(rand() % 201 - 100);
}

void Guard::draw(sf::RenderWindow& window)
{
    window.draw(m_Object);
}

//===========================================================
void Guard::move(sf::Vector2f Robot_loc, float deltatime) 
{
    if (!m_canMove)
    {
        sf::Vector2f direction = Robot_loc - m_position;
        float distance = std::sqrt(direction.x * direction.x + direction.y * direction.y);

        // ����� ���� ���� ������� (����, 5 �������)
        float targetRadius = 5.0f;

        if (distance > targetRadius) {
            direction /= distance; // ���������� �� ����� ������
            sf::Vector2f velocity = direction * moveSpeed * deltatime;

            m_Object.move(velocity); // ����� �� ��������
            m_position += velocity; // ����� ������ ������
        }
    }
    else
    {
        //captuareLocition();
        roundLoction();
        randomMove(deltatime);
        m_canMove = false;
    }
}
//========================================================
void Guard::randomMove(float deltaTime)
{

    // ����� ����� �������
    sf::Vector2f direction(static_cast<float>(rand() % 3 - 1), static_cast<float>(rand() % 3 - 1));
    if (direction.x == 0 && direction.y == 0) return; // �� ������ ��� (0,0) �� ����

    direction /= std::sqrt(direction.x * direction.x + direction.y * direction.y); // ���������� �� ������
    sf::Vector2f velocity = direction * moveSpeed * deltaTime;

    m_Object.move(velocity); // ����� �� ��������
    m_position += velocity; // ����� ������ ������

}
//=====================================================

//=========================captuareLocition==============*
void Guard::captuareLocition()//���� �� ������ ����� ���� ��� �����
{
    if (static_cast<int>(m_position.x) % 50 < 7)
        m_position.x -= (static_cast<int>(m_position.x) % 50);

    if (static_cast<int>(m_position.y) % 50 < 7)
        m_position.y -= (static_cast<int>(m_position.y) % 50);

    if (static_cast<int>(m_position.x) % 50 > 43)
        m_position.x += (50 - (static_cast<int>(m_position.x) % 50));

    if (static_cast<int>(m_position.y) % 50 > 43)
        m_position.y += (50 - (static_cast<int>(m_position.y) % 50));

    m_Object.setPosition(m_position);
}
//===================================================
void Guard::roundLoction()//i need to check why i need them both*
{

    // ����� ������ ����� ����� ����� ������ �-50
    m_position.x = std::round(m_position.x / 50.0f) * 50.0f;
    m_position.y = std::round(m_position.y / 50.0f) * 50.0f;

    // ����� ������ �� ��������
    m_Object.setPosition(m_position);
}







//// Getters
//sf::Vector2f Guard::getPosition() const {
//    return m_position;
//}

bool Guard::isFrozen() const {
    return frozen;
}

int Guard::getFreezeDuration() const {
    return freezeDuration;
}


//colisitions
//=================================================
//HameObject
void Guard::handleCollision(GameObject& gameObject)
{
    gameObject.handleCollision(*this);
}
//=====================================================
//Wall
void Guard::handleCollision(Wall& gameObject)
{
    std::cout << "in  \n";
    m_canMove = true;
}













////void Guard::moveTowards(sf::Vector2f Robot_loc, float deltatime, std::vector<sf::RectangleShape*>& walls) {
////    if (frozen) return;
////
////    // ����� ����� ������
////    sf::Vector2f direction = Robot_loc - m_position;
////    float distance = std::sqrt(direction.x * direction.x + direction.y * direction.y);
////
////    // ���������� �� ������
////    if (distance > 0.1f) {
////        direction /= distance; // ����������
////    }
////
////    // ����� ������ ������
////    sf::Vector2f velocity = direction * moveSpeed * deltatime;
////
////    // ����� ������� �� �����
////    for (const auto& wall : walls) {
////        if (m_Object.getGlobalBounds().intersects(wall.getGlobalBounds())) {
////            // ����� ����� ������
////            velocity = -velocity;
////          //  std::cout << "Collision with wall detected! Reversing direction." << std::endl;
////
////            // ����� ����� ���� ����
////            m_Object.move(-velocity);
////            m_position -= velocity;
////
////            // ����� ���� (������: ����� ��� �����)
////           // m_Object.setFillColor(sf::Color::Yellow); // ����� ���
////            break;
////        }
////    }
////
////    // ����� ������
////    m_Object.move(velocity);
////    m_position += velocity;
////}
////
////void Guard::draw(sf::RenderWindow& window)
////{
////	window.draw(m_Object);
////}
//
// 
//
//// Methods
//
//
//void Guard::freeze(int duration) {
//    frozen = true;
//    freezeDuration = duration;
//}
//
//void Guard::updateFreezeStatus() {
//    if (frozen && freezeDuration > 0) {
//        freezeDuration--;
//        if (freezeDuration == 0)
//            frozen = false;
//
//    }
//}
//
//
//
//
//
////#include "Guard.h"
////
////Guard::Guard(sf::Vector2f position, const char type)
////	:GameObject(position, type)
////{
////}
////
////sf::Sprite& Guard::gatSprite()
////{
////	return m_Object;
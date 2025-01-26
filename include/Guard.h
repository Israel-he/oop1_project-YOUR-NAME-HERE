#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Network.hpp>

#include "MovingObject.h"


class Guard :public MovingObject
{
  
public:

    // Constructor
    Guard(sf::Vector2f position, const char type);

    float randomnessFactor = 50.0f; // ���� �����


    // Getters
   // sf::Vector2f getPosition() const;
    bool isFrozen() const;
    int getFreezeDuration() const;

    // Methods
    void move(sf::Vector2f Robot_loc, float deltatime); // ����� ������ ������
    void freeze(int duration);                     // ����� ����� ���� ���
    void updateFreezeStatus();                     // ����� ����� �����
    virtual void draw(sf::RenderWindow& window) override; // ���� ����� �����

private:

    sf::Vector2f uniqueOffset;  // ����� ��� ������� ��� ����
    sf::Vector2f randomOffset; // ����� ������� ������ �����
    float moveSpeed = 50.f;
    float offsetRange = 100.0f;
    bool frozen;               // ��� ����� ����
    int freezeDuration;       // ��� ���� ������ ����
};


//#pragma once
//#include "GameObject.h"
//
//class Guard : public GameObject
//{
//public:
//    Guard(sf::Vector2f position, const char type);
//
//    virtual void draw(sf::RenderWindow& window) override;
//
//    virtual sf::Sprite& gatSprite() override;
// 
//private:
//
// };
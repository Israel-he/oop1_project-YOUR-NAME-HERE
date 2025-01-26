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

    float randomnessFactor = 50.0f; // טווח ההזחה


    // Getters
   // sf::Vector2f getPosition() const;
    bool isFrozen() const;
    int getFreezeDuration() const;

    // Methods
    void move(sf::Vector2f Robot_loc, float deltatime); // תנועה לכיוון הרובוט
    void freeze(int duration);                     // הקפאת השומר למשך זמן
    void updateFreezeStatus();                     // עדכון סטטוס הקפאה
    virtual void draw(sf::RenderWindow& window) override; // ציור השומר בחלון

private:

    sf::Vector2f uniqueOffset;  // נקודת יעד ייחודית לכל שומר
    sf::Vector2f randomOffset; // פקטור רנדומלי ייחודי לשומר
    float moveSpeed = 50.f;
    float offsetRange = 100.0f;
    bool frozen;               // האם השומר קפוא
    int freezeDuration;       // משך הזמן שהשומר קפוא
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










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

     //Constructor
    Guard(sf::Vector2f position, const char type);

    float randomnessFactor = 50.0f; // טווח ההזחה


     //Getters
    sf::Vector2f getPosition() const;
    bool isFrozen() const;
    int getFreezeDuration() const;

     //Methods

    void freeze(int duration);                     // הקפאת השומר למשך זמן
    void updateFreezeStatus();                     // עדכון סטטוס הקפאה
    virtual void draw(sf::RenderWindow& window) override; // ציור השומר בחלון
    

    void move(sf::Vector2f Robot_loc, float deltatime) override; // תנועה לכיוון הרובוט
    void randomMove(float deltaTime);
    void captuareLocition();//from robot
    void roundLoction();//from robot
    
    //check collisions
    bool checkCollision(float deltaTime);
    virtual void handleCollision(GameObject& gameObject);
    virtual void handleCollision(Robot& gameObject) {};
    virtual void handleCollision(Guard& gameObject) {};
    virtual void handleCollision(Gift& gameObject) {};
    virtual void handleCollision(Wall& gameObject) ;//
    virtual void handleCollision(Rock& gameObject) {};
    virtual void handleCollision(Bomb& gameObject) {};
    virtual void handleCollision(MovingExplod& gameObject) {};
    virtual void handleCollision(Door& gameObject) {};

private:

    sf::Vector2f uniqueOffset;  // נקודת יעד ייחודית לכל שומר
    sf::Vector2f randomOffset; // פקטור רנדומלי ייחודי לשומר
    float moveSpeed = 50.f;
    float offsetRange = 100.0f;
    bool frozen;               // האם השומר קפוא
    int freezeDuration;       // משך הזמן שהשומר קפוא
    bool m_canMove = false;
};

/////////////////////

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

//#pragma once
//#include <SFML/Graphics.hpp>
//#include <SFML/System.hpp>
//#include <SFML/Window.hpp>
//#include <SFML/Audio.hpp>
//#include <SFML/Network.hpp>
//
//#include "MovingObject.h"
//#include "GameObject.h"
//
//
//class Guard :public MovingObject
//{
// 
//public:
//
//    // Constructor
//    Guard(sf::Vector2f position, const char type);
//    ~Guard()
//    {
//        int i = 9;
//      //  std::cout << "gurd is ded";
//    }
//
//
//    float randomnessFactor = 50.0f; // טווח ההזחה
//
//   
//    // Getters
//   // sf::Vector2f getPosition() const;
//    bool isFrozen() const;
//    int getFreezeDuration() const;
//
//    // Methods
//    void move(sf::Vector2f Robot_loc, float deltatime) {}; // תנועה לכיוון הרובוט
//    void move(sf::Vector2f target, float deltaTime, const std::vector<std::unique_ptr<GameObject>>& objects);
//    //void freeze(int duration);                     // הקפאת השומר למשך זמן
//   // void updateFreezeStatus();                     // עדכון סטטוס הקפאה
//    virtual void draw(sf::RenderWindow& window) override; // ציור השומר בחלון
//    bool isColliding(const sf::Vector2f& newPos, /*const*/ GameObject& other) const;
//    sf::Sprite& getSprit();
//
//    //check collisions
//            bool checkcollision(float deltatime);
//            virtual void handleCollision(GameObject& gameObject) {};
//            virtual void handleCollision(Robot& gameObject) {};
//            virtual void handleCollision(Guard& gameObject) {};
//            virtual void handleCollision(Gift& gameObject) {};
//            virtual void handleCollision(Wall& gameObject) {};//
//            virtual void handleCollision(Rock& gameObject) {};
//            virtual void handleCollision(Bomb& gameObject) {};
//            virtual void handleCollision(MovingExplod& gameObject) {};
//            virtual void handleCollision(Door& gameObject) {};
//private:
//    bool hasStartedMoving = false;
//    sf::Vector2f uniqueOffset;  // נקודת יעד ייחודית לכל שומר
//    sf::Vector2f randomOffset; // פקטור רנדומלי ייחודי לשומר
//    float moveSpeed = 30.f;
//    float offsetRange = 100.0f;
//    bool frozen;               // האם השומר קפוא
//    int freezeDuration;       // משך הזמן שהשומר קפוא
//   
//   
//};
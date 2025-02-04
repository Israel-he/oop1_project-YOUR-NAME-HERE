//need to fix rondom guard


#include "Guard.h"
#include <iostream>
#include <MainMenu.h>
// Constructor
Guard::Guard(sf::Vector2f position, const char type)
    :MovingObject(position, type), frozen(false), freezeDuration(0)
{
    randomOffset.x = static_cast<float>(rand() % 101 - 50) / 50.0f * randomnessFactor;
    randomOffset.y = static_cast<float>(rand() % 101 - 50) / 50.0f * randomnessFactor;
    uniqueOffset.x = static_cast<float>(rand() % 201 - 100);
    uniqueOffset.y = static_cast<float>(rand() % 201 - 100);
    roundLoction();
}

void Guard::draw(sf::RenderWindow& window)
{
    window.draw(m_Object);
}
//========================
void Guard::setFirstLoc()
{
    m_position = m_firstPosition;
    m_Object.setPosition(m_firstPosition);
}

//===========================================================
void Guard::move(sf::Vector2f Robot_loc, float deltatime) 
{
    if (!m_canMove)
    {
        sf::Vector2f direction = Robot_loc - m_position;
        float distance = std::sqrt(direction.x * direction.x + direction.y * direction.y);

        // הגדרת מרחק מטרה מינימלי (למשל, 5 פיקסלים)
        float targetRadius = 5.0f;

        if (distance > targetRadius) {
            direction /= distance; // נורמליזציה של כיוון התנועה
            sf::Vector2f velocity = direction * moveSpeed * deltatime;

            m_Object.move(velocity); // תנועה של האובייקט
            m_position += velocity; // עדכון המיקום הפנימי
        }
    }
    else
    {
        captuareLocition();
        roundLoction();
        randomMove(deltatime);
        m_canMove = false;
    }
}
//========================================================
void Guard::randomMove(float deltaTime)
{

    // יצירת כיוון רנדומלי
    sf::Vector2f direction(static_cast<float>(rand() % 3 - 1), static_cast<float>(rand() % 3 - 1));
    if (direction.x == 0 && direction.y == 0) return; // אם הכיוון הוא (0,0) לא לזוז

    direction /= std::sqrt(direction.x * direction.x + direction.y * direction.y); // נורמליזציה של הכיוון
    sf::Vector2f velocity = direction * moveSpeed * deltaTime;

    m_Object.move(velocity); // תנועה של האובייקט
    m_position += velocity; // עדכון המיקום הפנימי

}
//=====================================================

//=========================captuareLocition==============*
void Guard::captuareLocition()//מחשב את השארית ומאפס אותה לפי הצורך
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

    // עיגול המיקום למספר הקרוב ביותר שמתחלק ב-50
    m_position.x = std::round(m_position.x / 50.0f) * 50.0f;
    m_position.y = std::round(m_position.y / 50.0f) * 50.0f;

    // עדכון המיקום של האובייקט
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
//=======================
bool Guard::getIsdispose()
{
    return m_isDispose;
}

//colocations
//=================================================
//GameObject
void Guard::handleCollision(GameObject& gameObject)
{
    gameObject.handleCollision(*this);
}

//Robot
void Guard::handleCollision(Robot& gameObject)
{
    if (m_Object.getGlobalBounds().intersects(gameObject.getSprit().getGlobalBounds()))
    {
        GameControl::m_restartGame = true;
        gameObject.handleCollision(*this);

    }
}

//=====================================================
//Wall
void Guard::handleCollision(Wall& gameObject)
{
    std::cout << "in  \n";
    m_canMove = true;
} 

//Rock
void Guard::handleCollision(Rock& gameObject)
{
    std::cout << "u  \n";
    m_canMove = true;
}

//MovingExplod
void Guard::handleCollision(MovingExplod& gameObject)
{
    m_isDispose = true;
}







void Guard::moveTowards(sf::Vector2f target, float deltaTime,   std::vector<std::unique_ptr<GameObject>>& objects) {

    // חישוב כיוון למטרה
    sf::Vector2f direction = target - m_position;

    // רשימת כיוונים אפשריים
    std::vector<std::pair<sf::Vector2f, float>> directionsWithDistances =
    {
        {sf::Vector2f(1.f, 0.f), 0.f},  // ימינה
        {sf::Vector2f(-1.f, 0.f), 0.f}, // שמאלה
        {sf::Vector2f(0.f, 1.f), 0.f},  // למטה
        {sf::Vector2f(0.f, -1.f), 0.f}  // למעלה
    };

    // חישוב המרחק לכל כיוון
    for (auto& dir : directionsWithDistances) {
        sf::Vector2f newPosition = m_position + dir.first;
        dir.second = std::hypot(target.x - newPosition.x, target.y - newPosition.y);
    }

    // מיון כיוונים לפי קרבה ליעד
    std::sort(directionsWithDistances.begin(), directionsWithDistances.end(),
        [](const std::pair<sf::Vector2f, float>& a, const std::pair<sf::Vector2f, float>& b) {
            return a.second < b.second;
        });

    // ניסיון תנועה בכיוון העדיף
    sf::Vector2f newPosition;
    bool isColliding = false;

    for (int i = 0; i < 4; i++) {
        newPosition = m_position + directionsWithDistances[i].first * moveSpeed * deltaTime;
        isColliding = false;

        for (const auto& obj : objects) {
            if (obj.get() != this && this->isColliding(newPosition, *obj)) {
                isColliding = true;
                break;
            }
        }

        if (!isColliding)
            break; // יציאה אם אין התנגשות
    }

    // אם כל הכיוונים חסומים, מנסים להזיז בפיקסלים בודדים
    if (isColliding) {
        for (float offset = 1.0f; offset <= 5.0f; offset += 1.0f) {
            for (int i = 0; i < 4; i++) {
                newPosition = m_position + directionsWithDistances[i].first * offset;

                isColliding = false;
                for (const auto& obj : objects) {
                    if (obj.get() != this && this->isColliding(newPosition, *obj)) {
                        isColliding = true;
                        break;
                    }
                }

                if (!isColliding)
                    break;
            }
            if (!isColliding)
                break;
        }
    }

    // **מנגנון למניעת תקיעה**
    if (isColliding) {
        newPosition = m_position + directionsWithDistances[0].first * 0.5f; // תנועה מזערית
        isColliding = false;

        for (const auto& obj : objects) {
            if (obj.get() != this && this->isColliding(newPosition, *obj)) {
                isColliding = true;
                break;
            }
        }

        // אם עדיין תקוע, מזיז בכיוון אקראי
        if (isColliding) {
            newPosition = m_position + sf::Vector2f((rand() % 3 - 1) * 0.5f, (rand() % 3 - 1) * 0.5f);
        }
    }

    // עדכון מיקום רק אם הוא השתנה
    if (newPosition != m_position) {
        m_position = newPosition;
        m_Object.setPosition(m_position);
    }
}

//===================================
void Guard::setfreezeDuration(int deltaTime)
{
    freezeDuration = deltaTime;
}
//======================================
bool Guard::isColliding(const sf::Vector2f& newPos,   GameObject& other) const {
    // קבלת הגבולות של הריבוע החוסם של האובייקט הנוכחי
    sf::FloatRect thisBounds = m_Object.getGlobalBounds();

    // עדכון המיקום של האובייקט הנוכחי על פי המיקום החדש
    thisBounds.left = newPos.x;
    thisBounds.top = newPos.y;

    // קבלת הגבולות של הריבוע החוסם של האובייקט השני
    sf::FloatRect otherBounds = other.getSprit().getGlobalBounds();

    // בדיקת התנגשויות בין שני הריבועים החוסמים
    return thisBounds.intersects(otherBounds);
}



//==============================================

////void Guard::moveTowards(sf::Vector2f Robot_loc, float deltatime, std::vector<sf::RectangleShape*>& walls) {
////    if (frozen) return;
////
////    // חישוב כיוון התנועה
////    sf::Vector2f direction = Robot_loc - m_position;
////    float distance = std::sqrt(direction.x * direction.x + direction.y * direction.y);
////
////    // נורמליזציה של הכיוון
////    if (distance > 0.1f) {
////        direction /= distance; // נורמליזציה
////    }
////
////    // חישוב מהירות התנועה
////    sf::Vector2f velocity = direction * moveSpeed * deltatime;
////
////    // בדיקת קוליזיה עם קירות
////    for (const auto& wall : walls) {
////        if (m_Object.getGlobalBounds().intersects(wall.getGlobalBounds())) {
////            // היפוך כיוון התנועה
////            velocity = -velocity;
////          //  std::cout << "Collision with wall detected! Reversing direction." << std::endl;
////
////            // מניעת תנועה לתוך הקיר
////            m_Object.move(-velocity);
////            m_position -= velocity;
////
////            // הוספת אפקט (לדוגמה: שינוי צבע השומר)
////           // m_Object.setFillColor(sf::Color::Yellow); // שינוי צבע
////            break;
////        }
////    }
////
////    // עדכון המיקום
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
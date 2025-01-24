#ifndef MAINMENU_H
#define MAINMENU_H
#include <SFML/Graphics.hpp>

class MainMenu
{
public:
    MainMenu();  // בנאי
    void run();  // מפעיל את חלון התפריט

private:
    sf::RenderWindow window;   
    sf::Font font;             // פונט להצגת טקסטים
    sf::Text startText;        // טקסט להתחלת משחק
    sf::Text helpText;         // טקסט לעזרה
    sf::Text exitText;         // טקסט ליציאה

    void handleEvents();       // מטפל באירועים
    void render();             // מצייר את החלון
    void startGame();          // מפעיל את המשחק
    void showHelp();           // מציג עזרה
};

#endif // MAINMENU_H
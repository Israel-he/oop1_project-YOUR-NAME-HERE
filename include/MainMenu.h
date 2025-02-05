#ifndef MAINMENU_H
#define MAINMENU_H

#include "GameControl.h"
#include <SFML/Graphics.hpp>

// ����� ������ �����
class MainMenu {
public:
    MainMenu();  // ����
    void run();  // ����� �� ���� ������

private:
    sf::RenderWindow window;   // ���� SFML
    sf::Font font;             // ���� ����� ������
    sf::Text startText;        // ���� ������ ����
    sf::Text helpText;         // ���� �����
    sf::Text exitText;         // ���� ������

    void handleEvents();       // ���� ��������
    void render();             // ����� �� �����
    void startGame();          // ����� �� �����
    void showHelp();           // ���� ����
};

#endif // MAINMENU_H

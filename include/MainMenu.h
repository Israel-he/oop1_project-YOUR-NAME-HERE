#ifndef MAINMENU_H
#define MAINMENU_H
#include <SFML/Graphics.hpp>

class MainMenu
{
public:
    MainMenu();  // ����
    void run();  // ����� �� ���� ������

private:
    sf::RenderWindow window;   
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
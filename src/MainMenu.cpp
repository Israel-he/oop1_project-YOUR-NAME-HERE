#include "MainMenu.h"
#include <iostream>
#include <fstream>

MainMenu::MainMenu()
    : window(sf::VideoMode(800, 600), "Main Menu") {
    // טוען פונט
    if (!font.loadFromFile("ARIAL.TTF")) {
        std::cerr << "Error loading font!" << std::endl;
        exit(-1);
    }

    // הגדרת טקסטים
    startText.setFont(font);
    startText.setString("Start Game");
    startText.setCharacterSize(40);
    startText.setPosition(300, 200);

    helpText.setFont(font);
    helpText.setString("Help");
    helpText.setCharacterSize(40);
    helpText.setPosition(300, 300);

    exitText.setFont(font);
    exitText.setString("Exit");
    exitText.setCharacterSize(40);
    exitText.setPosition(300, 400);
}

void MainMenu::run() {
    while (window.isOpen()) {
        handleEvents();
        render();
    }
}

void MainMenu::handleEvents() {
    sf::Event event;
    while (window.pollEvent(event)) {
        if (event.type == sf::Event::Closed) {
            window.close();
        }
        if (event.type == sf::Event::MouseButtonPressed) {
            sf::Vector2i mousePos = sf::Mouse::getPosition(window);

            if (startText.getGlobalBounds().contains(mousePos.x, mousePos.y)) {
                window.close();
                startGame();
            }
            if (helpText.getGlobalBounds().contains(mousePos.x, mousePos.y)) {
                showHelp();
            }
            if (exitText.getGlobalBounds().contains(mousePos.x, mousePos.y)) {
                window.close();
            }
        }
    }
}

void MainMenu::render() {
    window.clear(sf::Color::Cyan);
    window.draw(startText);
    window.draw(helpText);
    window.draw(exitText);
    window.display();
}

void MainMenu::startGame() {
    std::cout << "Starting the game..." << std::endl;
    // כאן יש להוסיף את קוד המשחק

    srand(time(NULL));
    GameControl  b;
    while (b.windowIsOpen())
    {
        b.render();
        b.update();

    }
}

void MainMenu::showHelp() {

    std::ifstream helpFile("help.txt");
    if (!helpFile) {
        std::cerr << "Error: Could not open help file!" << std::endl;
        return;
    }

    std::string helpContent;
    char c;

    while (helpFile.get(c)) {
        helpContent += c;
    }

    helpFile.close();

    // יצירת חלון עזרה
    sf::RenderWindow helpWindow(sf::VideoMode(600, 400), "Help", sf::Style::Close);
    sf::Text helpTextDisplay;
    helpTextDisplay.setFont(font);
    helpTextDisplay.setString(helpContent);
    helpTextDisplay.setCharacterSize(20);
    helpTextDisplay.setFillColor(sf::Color::Black);
    helpTextDisplay.setPosition(10.f, 10.f);

    // כפתור Back
    sf::RectangleShape backButton(sf::Vector2f(100.f, 50.f));
    backButton.setFillColor(sf::Color::Red);
    backButton.setPosition(250.f, 320.f);

    sf::Text backText;
    backText.setFont(font);
    backText.setString("Back");
    backText.setCharacterSize(20);
    backText.setFillColor(sf::Color::White);
    backText.setPosition(backButton.getPosition().x + 25, backButton.getPosition().y + 10);

    // לולאת החלון
    while (helpWindow.isOpen()) {
        sf::Event event;
        while (helpWindow.pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
                helpWindow.close();
            }

            if (event.type == sf::Event::MouseButtonPressed) {
                if (event.mouseButton.button == sf::Mouse::Left) {
                    sf::Vector2i mousePos = sf::Mouse::getPosition(helpWindow);
                    if (backButton.getGlobalBounds().contains(static_cast<sf::Vector2f>(mousePos))) {
                        helpWindow.close(); // סוגר את חלון העזרה
                    }
                }
            }
        }

        helpWindow.clear(sf::Color::Red);
        helpWindow.draw(helpTextDisplay);
        helpWindow.draw(backButton);
        helpWindow.draw(backText);
        helpWindow.display();
    }

}
//#include "MainMenu.h"
//#include <iostream>
//#include <fstream>
//
//MainMenu::MainMenu()
//    : window(sf::VideoMode(800, 600), "Main Menu") 
//{
//    // טוען פונט
//    /*if (!font.loadFromFile("arial.ttf")) {
//        std::cerr << "Error loading font!" << std::endl;
//        exit(-1);
//    }*/
//
//    // הגדרת טקסטים
//    startText.setFont(font);
//    startText.setString("Start Game");
//    startText.setCharacterSize(40);
//    startText.setPosition(300, 200);
//
//    helpText.setFont(font);
//    helpText.setString("Help");
//    helpText.setCharacterSize(40);
//    helpText.setPosition(300, 300);
//
//    exitText.setFont(font);
//    exitText.setString("Exit");
//    exitText.setCharacterSize(40);
//    exitText.setPosition(300, 400);
//}
//
//void MainMenu::run() {
//    while (window.isOpen()) {
//        handleEvents();
//        render();
//    }
//}
//
//void MainMenu::handleEvents() {
//    sf::Event event;
//    while (window.pollEvent(event)) {
//        if (event.type == sf::Event::Closed) {
//            window.close();
//        }
//        if (event.type == sf::Event::MouseButtonPressed) {
//            sf::Vector2i mousePos = sf::Mouse::getPosition(window);
//
//            if (startText.getGlobalBounds().contains(mousePos.x, mousePos.y)) {
//                window.close();
//                startGame();
//            }
//            if (helpText.getGlobalBounds().contains(mousePos.x, mousePos.y)) {
//                showHelp();
//            }
//            if (exitText.getGlobalBounds().contains(mousePos.x, mousePos.y)) {
//                window.close();
//            }
//        }
//    }
//}
//
//void MainMenu::render() {
//    window.clear();
//    window.draw(startText);
//    window.draw(helpText);
//    window.draw(exitText);
//    window.display();
//}
//
//void MainMenu::startGame() {
//    std::cout << "Starting the game..." << std::endl;
//    // כאן יש להוסיף את קוד המשחק
//}
//
//void MainMenu::showHelp() {
//    std::ifstream helpFile("help.txt");
//    if (!helpFile) {
//        std::cout << "Error: Could not open help file!" << std::endl;
//        return;
//    }
//    std::string line;
//    while (std::getline(helpFile, line)) {
//        std::cout << line << std::endl;
//    }
//    helpFile.close();
//}
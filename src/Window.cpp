#include "Window.h"

Window::Window(unsigned int cols, unsigned int rows)
    :m_videoMode(cols, rows)
{
    createWindow();
}

//================================================
//creating the window
void Window::createWindow()
{
    m_window.create(m_videoMode, "Bomberman", sf::Style::Titlebar | sf::Style::Close);
}
//=================================================
//check if the window is open
const bool Window::windowisOpen() const
{
    return m_window.isOpen();
}
//==================================================

sf::Sprite Window::create(sf::Texture& pic,sf::Vector2f position)
{
    auto result = sf::Sprite(pic);
    result.setPosition(position);
    
    return result;
}


//
// Created by valentin mougenot on 01/11/2022.
//

#ifndef FRACTALS_APP_HPP
#define FRACTALS_APP_HPP

#include <string>
#include <SFML/Graphics.hpp>


class App {
private:
    sf::RenderWindow window;
    std::string name;

public:
    explicit App(const std::string& name);
    void render();
};

#endif //FRACTALS_APP_HPP

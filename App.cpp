//
// Created by valentin mougenot on 01/11/2022.
//

#include "App.hpp"
#include "Settings.hpp"

#include "Julia.hpp"
#include "Mandelbrot.hpp"
#include "BurningShip.hpp"
#include "Newton.hpp"

App::App(const std::string &name) {
    App::name = name;
    window.create(sf::VideoMode(WINDOW_WIDTH, WINDOW_HEIGHT), name);
}

void App::render() {
    Fractal *fractal = new Julia();
    fractal->update();

    sf::Font font;
    font.loadFromFile("/System/Library/Fonts/Helvetica.ttc" );
    sf::Text text;
    text.setFont(font);

    while (window.isOpen()) {
        sf::Event event {};
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
                window.close();
            }

            if (event.type == sf::Event::KeyPressed) {
                if (event.key.code == sf::Keyboard::Escape) {
                    window.close();
                }
                if (event.key.code == sf::Keyboard::M) {
                    delete fractal;
                    fractal = new Mandelbrot();
                    fractal->update();
                }
                if (event.key.code == sf::Keyboard::J) {
                    delete fractal;
                    fractal = new Julia();
                    fractal->update();
                }
                if (event.key.code == sf::Keyboard::B) {
                    delete fractal;
                    fractal = new BurningShip();
                    fractal->update();
                }
                if (event.key.code == sf::Keyboard::N) {
                    delete fractal;
                    fractal = new Newton();
                    fractal->update();
                }
                if (event.key.code == sf::Keyboard::Up) {
                    fractal->move(0, (fractal->getYMax() - fractal->getYMin()) * -0.2);
                    fractal->update();
                }
                if (event.key.code == sf::Keyboard::Down) {
                    fractal->move(0, (fractal->getYMax() - fractal->getYMin()) * 0.2);
                    fractal->update();
                }
                if (event.key.code == sf::Keyboard::Left) {
                    fractal->move((fractal->getXMax() - fractal->getXMin()) * -0.2, 0);
                    fractal->update();
                }
                if (event.key.code == sf::Keyboard::Right) {
                    fractal->move((fractal->getXMax() - fractal->getXMin()) * 0.2, 0);
                    fractal->update();
                }
                if (fractal->isJulia()) {
                    if (event.key.code == sf::Keyboard::A) {
                        ((Julia *) fractal)->decreaseCRe();
                        fractal->update();
                    }
                    if (event.key.code == sf::Keyboard::D) {
                        ((Julia *) fractal)->increaseCRe();
                        fractal->update();
                    }
                    if (event.key.code == sf::Keyboard::W) {
                        ((Julia *) fractal)->increaseCIm();
                        fractal->update();
                    }
                    if (event.key.code == sf::Keyboard::S) {
                        ((Julia *) fractal)->decreaseCIm();
                        fractal->update();
                    }
                }
                if (event.key.code == sf::Keyboard::O) {
                    Fractal::nextColor();
                    fractal->update();
                }
                if (event.key.code == sf::Keyboard::P) {
                    Fractal::previousColor();
                    fractal->update();
                }
            }

            if (event.type == sf::Event::MouseWheelScrolled) {
                if (event.mouseWheelScroll.delta != 0) {
                    fractal->zoom(sf::Mouse::getPosition(window).x, sf::Mouse::getPosition(window).y, (event.mouseWheelScroll.delta > 0) ? 1.5 : 0.66);
                    fractal->update();
                }
            }

            if (event.type == sf::Event::MouseButtonPressed) {
                if (event.mouseButton.button == sf::Mouse::Left) {
                    fractal->doubleMaxIterations();
                    fractal->update();
                }
                if (event.mouseButton.button == sf::Mouse::Right) {
                    fractal->halfMaxIterations();
                    fractal->update();
                }
            }
        }
        window.clear();
        window.draw(fractal->getSprite());
        std::string str = "Zoom: x" + std::to_string(fractal->getZm()) + "\nMax iterations: " + std::to_string(fractal->getMaxIterations());
        if (fractal->isJulia()) {
            str += "\nC: " + std::to_string(((Julia *) fractal)->getCRe()) + " + " + std::to_string(((Julia *) fractal)->getCIm()) + "i";
        }
        text.setString(str);
        window.draw(text);
        window.display();
    }

}

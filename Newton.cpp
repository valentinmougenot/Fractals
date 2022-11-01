//
// Created by valentin mougenot on 01/11/2022.
//

#include "Newton.hpp"
#include "Settings.hpp"

Newton::Newton() {
    xMin = -2;
    xMax = 2;
    yMin = -2;
    yMax = 2;
}

Newton::Newton(const std::complex<double> &root1, const std::complex<double> &root2, const std::complex<double> &root3)
        : root1(root1), root2(root2), root3(root3) {
    xMin = -2;
    xMax = 2;
    yMin = -2;
    yMax = 2;
}

void Newton::createImage() {
#pragma omp parallel for
    for (int px = 0; px < WINDOW_WIDTH; ++px) {
        for (int py = 0; py < WINDOW_HEIGHT; ++py) {
            std::complex<double> z = std::complex<double>(xMin + (xMax - xMin) * px / WINDOW_WIDTH,
                                                         yMin + (yMax - yMin) * py / WINDOW_HEIGHT);
            int i = 0;
            for(; i < maxIterations; ++i) {
                std::complex<double> f = z * z * z - std::complex<double>(1, 0);
                std::complex<double> df = std::complex<double>(3, 0) * z * z;
                z = z - f / df;
                if (std::abs(z - root1) < 0.0001 || std::abs(z - root2) < 0.0001 || std::abs(z - root3) < 0.0001) {
                    break;
                }
            }

            if (i == maxIterations) {
                image.setPixel(px, py, sf::Color::Black);
            }
            else if (std::abs(z - root1) < 0.0001) {
                image.setPixel(px, py, sf::Color(255 - static_cast<sf::Uint8>(255.0 * i / maxIterations), 0, 0));
            }
            else if (std::abs(z - root2) < 0.0001) {
                image.setPixel(px, py, sf::Color(0, 255 - static_cast<sf::Uint8>(255.0 * i / maxIterations), 0));
            }
            else if (std::abs(z - root3) < 0.0001) {
                image.setPixel(px, py, sf::Color(0, 0, 255 - static_cast<sf::Uint8>(255.0 * i / maxIterations)));
            }
        }
    }
}

bool Newton::isNewton() const {
    return true;
}

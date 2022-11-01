//
// Created by valentin mougenot on 01/11/2022.
//

#ifndef FRACTALS_NEWTON_HPP
#define FRACTALS_NEWTON_HPP

#include "Fractal.hpp"
#include <cmath>
#include <complex>
#include <vector>

class Newton: public Fractal {
private:
    std::complex<double> root1 = std::complex<double>(1, 0);
    std::complex<double> root2 = std::complex<double>(-0.5, sqrt(3) / 2);
    std::complex<double> root3 = std::complex<double>(-0.5, -sqrt(3) / 2);

    static inline const std::vector<sf::Color> colors = {sf::Color::Red, sf::Color::Green, sf::Color::Blue};

public:
    Newton();

    Newton(const std::complex<double> &root1, const std::complex<double> &root2, const std::complex<double> &root3);

    void createImage() override;

    bool isNewton() const override;
};


#endif //FRACTALS_NEWTON_HPP

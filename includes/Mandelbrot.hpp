//
// Created by valentin mougenot on 01/11/2022.
//

#ifndef FRACTALS_MANDELBROT_HPP
#define FRACTALS_MANDELBROT_HPP

#include "Fractal.hpp"

class Mandelbrot: public Fractal {
public:
    Mandelbrot();
    void createImage() override;

    bool isMandelbrot() const override;
};


#endif //FRACTALS_MANDELBROT_HPP

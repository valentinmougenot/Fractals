//
// Created by valentin mougenot on 01/11/2022.
//

#ifndef FRACTALS_JULIA_HPP
#define FRACTALS_JULIA_HPP

#include "Fractal.hpp"

class Julia : public Fractal {
private:
    double cRe = -1;
    double cIm = 0;

public:
    Julia();
    void createImage() override;
    bool isJulia() const override;

    void increaseCRe();
    void decreaseCRe();
    void increaseCIm();
    void decreaseCIm();

    double getCRe() const;

    double getCIm() const;
};

#endif //FRACTALS_JULIA_HPP

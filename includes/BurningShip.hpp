//
// Created by valentin mougenot on 01/11/2022.
//

#ifndef FRACTALS_BURNINGSHIP_HPP
#define FRACTALS_BURNINGSHIP_HPP

#include "Fractal.hpp"

class BurningShip: public Fractal {
public:
    BurningShip();
    void createImage() override;

    bool isBurningShip() const override;

};


#endif //FRACTALS_BURNINGSHIP_HPP

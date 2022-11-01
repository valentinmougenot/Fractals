//
// Created by valentin mougenot on 01/11/2022.
//

#include <cmath>

#include "BurningShip.hpp"
#include "Settings.hpp"

BurningShip::BurningShip() {
    xMin = -2.5;
    xMax = 1.5;
    yMin = -2;
    yMax = 1;
}

void BurningShip::createImage() {
#pragma omp parallel for
    for(int px = 0; px < WINDOW_WIDTH; ++px) {
        for(int py = 0; py < WINDOW_HEIGHT; ++py) {
            double x0 = xMin + (xMax - xMin) * px / WINDOW_WIDTH;
            double y0 = yMin + (yMax - yMin) * py / WINDOW_HEIGHT;

            double x = 0;
            double y = 0;

            int i = 0;
            for(; i < maxIterations; ++i) {
                x = std::abs(x);
                y = std::abs(y);
                double x2 = x * x;
                double y2 = y * y;
                if(x2 + y2 > 4) {
                    break;
                }
                y = 2 * x * y + y0;
                x = x2 - y2 + x0;
            }

            if (i == maxIterations) {
                i = 0;
            }
            size_t nColor = colorPalette[nColorPalette].size() - 1;
            double mu = 1.0 * i / maxIterations;
            mu *= nColor;
            int iMu = static_cast<int>(mu);
            auto color1 = colorPalette[nColorPalette][iMu];
            auto color2 = colorPalette[nColorPalette][(iMu + 1 > nColor) ? nColor : iMu + 1];
            sf::Color color = linearInterpolation(color1, color2, mu - iMu);
            image.setPixel(px, py, color);
        }
    }
}

bool BurningShip::isBurningShip() const {
    return true;
}

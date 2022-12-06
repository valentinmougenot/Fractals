//
// Created by valentin mougenot on 01/11/2022.
//

#include "../includes/Julia.hpp"
#include "../includes/Settings.hpp"

Julia::Julia() {
    xMin = -2;
    xMax = 2;
    yMin = -1.5;
    yMax = 1.5;
}

void Julia::createImage() {
    for(int px = 0; px < WINDOW_WIDTH; ++px) {
        for(int py = 0; py < WINDOW_HEIGHT; ++py) {
            double x = xMin + (xMax - xMin) * px / WINDOW_WIDTH;
            double y = yMin + (yMax - yMin) * py / WINDOW_HEIGHT;

            int i = 0;
            for(; i < maxIterations; ++i) {
                double x2 = x * x;
                double y2 = y * y;
                if(x2 + y2 > 4) {
                    break;
                }
                y = 2 * x * y + cIm;
                x = x2 - y2 + cRe;
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

bool Julia::isJulia() const {
    return true;
}

void Julia::increaseCRe() {
    cRe += 0.1;
}

void Julia::decreaseCRe() {
    cRe -= 0.1;
}

void Julia::increaseCIm() {
    cIm += 0.1;
}

void Julia::decreaseCIm() {
    cIm -= 0.1;
}

double Julia::getCRe() const {
    return cRe;
}

double Julia::getCIm() const {
    return cIm;
}



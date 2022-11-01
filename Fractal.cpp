//
// Created by valentin mougenot on 01/11/2022.
//

#include "Fractal.hpp"
#include "Settings.hpp"


Fractal::Fractal() {
    image.create(WINDOW_WIDTH, WINDOW_HEIGHT);
}

void Fractal::zoom(double x, double y, double factor) {
    double cX = xMin + (xMax - xMin) * x / WINDOW_WIDTH;
    double cY = yMin + (yMax - yMin) * y / WINDOW_HEIGHT;

    double x0 = cX - (xMax - xMin) / 2 / factor;
    double y0 = cY - (yMax - yMin) / 2 / factor;
    xMax = cX + (xMax - xMin) / 2 / factor;
    xMin = x0;
    yMax = cY + (yMax - yMin) / 2 / factor;
    yMin = y0;

    zm *= factor;
}

void Fractal::move(double x, double y) {
    xMin += x;
    xMax += x;
    yMin += y;
    yMax += y;
}

void Fractal::setMaxIterations(int maxIterations) {
    Fractal::maxIterations = maxIterations;
}

void Fractal::setXMin(double xMin) {
    Fractal::xMin = xMin;
}

void Fractal::setXMax(double xMax) {
    Fractal::xMax = xMax;
}

void Fractal::setYMin(double yMin) {
    Fractal::yMin = yMin;
}

void Fractal::setYMax(double yMax) {
    Fractal::yMax = yMax;
}

void Fractal::doubleMaxIterations() {
    Fractal::maxIterations *= 2;
}

void Fractal::halfMaxIterations() {
    if (Fractal::maxIterations > 1) {
        Fractal::maxIterations /= 2;
    }
}

void Fractal::update() {
    createImage();
    texture.loadFromImage(image);
    sprite.setTexture(texture);
}

double Fractal::getXMin() const {
    return xMin;
}

double Fractal::getXMax() const {
    return xMax;
}

double Fractal::getYMin() const {
    return yMin;
}

double Fractal::getYMax() const {
    return yMax;
}

double Fractal::getZm() const {
    return zm;
}


const sf::Sprite &Fractal::getSprite() const {
    return sprite;
}

bool Fractal::isJulia() const {
    return false;
}

bool Fractal::isMandelbrot() const {
    return false;
}

bool Fractal::isBurningShip() const {
    return false;
}

bool Fractal::isNewton() const {
    return false;
}

int Fractal::getMaxIterations() const {
    return maxIterations;
}

void Fractal::nextColor() {
    nColorPalette = (nColorPalette + 1) % colorPalette.size();
}

void Fractal::previousColor() {
    if (nColorPalette == 0) {
        nColorPalette = colorPalette.size() - 1;
    }
    else {
        --nColorPalette;
    }
}

Fractal::~Fractal() {

}

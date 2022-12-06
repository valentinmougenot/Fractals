//
// Created by valentin mougenot on 01/11/2022.
//

#ifndef FRACTALS_FRACTAL_HPP
#define FRACTALS_FRACTAL_HPP

#include <SFML/Graphics.hpp>
#include <vector>


class Fractal {
protected:
    double xMin;
    double xMax;
    double yMin;
    double yMax;
    int maxIterations = 128;
    double zm = 1.0;

    sf::Image image;
    sf::Texture texture;
    sf::Sprite sprite;

    static inline size_t nColorPalette = 0;

    static inline std::vector<std::vector<sf::Color>> colorPalette = {
            {{0, 7, 0},
             {32, 107, 203},
             {237, 255, 255},
             {255, 170, 0},
             {0, 2, 0}},

            {{0, 0, 0},
             {213, 67, 31},
             {251, 255, 121},
             {62, 223, 89},
             {43, 30, 89},
             {0, 255, 89}},
    };

public:
    Fractal();
    void zoom(double x, double y, double factor);
    void move(double x, double y);
    void setMaxIterations(int maxIterations);
    void setXMin(double xMin);
    void setXMax(double xMax);
    void setYMin(double yMin);
    void setYMax(double yMax);
    void doubleMaxIterations();
    void halfMaxIterations();
    virtual void createImage() = 0;
    void update();

    // GETTERS
    double getXMin() const;
    double getXMax() const;
    double getYMin() const;
    double getYMax() const;
    double getZm() const;
    int getMaxIterations() const;
    const sf::Sprite &getSprite() const;

    // Class booleans
    virtual bool isJulia() const;
    virtual bool isMandelbrot() const;
    virtual bool isBurningShip() const;
    virtual bool isNewton() const;

    static void nextColor();
    static void previousColor();

    static sf::Color linearInterpolation(const sf::Color& v, const sf::Color& u, double a)
    {
        double b = 1 - a;
        return sf::Color(b * v.r + a * u.r, b * v.g + a * u.g, b * v.b + a * u.b) ;
    }

    virtual ~Fractal();
};


#endif //FRACTALS_FRACTAL_HPP

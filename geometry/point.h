#ifndef POINT_H
#define POINT_H

#include <math.h>
#include <vector>

#include "object.h"
/* TODO - review class */
class IASPP_PUBLIC Point : public Object
{
public:
    Point();
    Point(int x, int y);
    Point(SDL_Point *p);

    virtual ~Point();

    int x;
    int y;

    double length();
    Point* add(Point &p);
    Point* clone();
    void copyFrom(Point &p);

    static double distance(Point &p1, Point &p2);
    bool equals(Point *p);

    //Determina um ponto entre dois pontos especificados.
    //quanto mais próximo f for de 0, mais próximo de p1
    static Point* interpolate(Point &p1, Point &p2, double f);

    //Dimensiona o segmento de linha entre (0,0) e o ponto atual até um comprimento definido.
    void normalize(double value);
    //move o ponto
    void offset(int dx, int dy);

    static Point *polar(double leng, double angle);

    void setTo(int xa, int ya);
    Point *subtract(Point &p);
    virtual std::string toString();

    bool isInPolygon(std::vector<int> &xPoints, std::vector<int> &yPoints);

    SDL_Point *toSDL();

private:
    double getAngle();
};

#endif // POINT_H

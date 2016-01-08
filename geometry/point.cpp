#include "point.h"

Point::Point():Object()
{
    this->x = 0;
    this->y = 0;
}

Point::Point(int x, int y):Object()
{
    this->x = x;
    this->y = y;
}

Point::Point(SDL_Point *p):Object()
{
    this->x = p->x;
    this->y = p->y;
}

Point::~Point() { }

double Point::length()
{
    return sqrt(pow(this->x, 2) + pow(this->y, 2));
}

Point *Point::add(Point &p)
{
    return new Point(this->x + p.x, this->y + p.y);
}

Point *Point::clone()
{
    return new Point(this->x, this->y);
}

void Point::copyFrom(Point &p)
{
    this->x = p.x;
    this->y = p.y;
}

double Point::distance(Point &p1, Point &p2)
{
    double dx = p1.x - p2.x;
    double dy = p1.y - p2.y;
    return sqrt(pow(dx,2) + pow(dy,2));
}

bool Point::equals(Point *p)
{
    return (this->x == p->x) && (this->y == p->y);
}

//TODO testar//validar
Point *Point::interpolate(Point &p1, Point &p2, double f)
{
    if(f<0) f = 0;
    if(f>1) f = 1;
    double dist = Point::distance(p1, p2);
    double angle = (p1.x - p2.x)/dist;
    double begin = p1.length();

    begin += dist*(1-f);

    return Point::polar(begin, angle);
}

//TODO testar//validar
void Point::normalize(double value)
{
    double deg = this->getAngle();
    Point* p = Point::polar(value, deg);
    this->x = p->x;
    this->y = p->y;
    delete p;
}

void Point::offset(int dx, int dy)
{
    this->x += dx;
    this->y += dy;
}

//TODO testar//validar
Point *Point::polar(double leng, double angle)
{
    double _x = leng * cos(angle);
    double _y = leng * sin(angle);

    return new Point(_x, _y);
}

void Point::setTo(int xa, int ya)
{
    this->x = xa;
    this->y = ya;
}

Point *Point::subtract(Point &p)
{
    return new Point(this->x -p.x, this->y -p.y);
}

std::string Point::toString()
{
    return "x: " + std::to_string(this->x) + " y: " + std::to_string(this->y);
}

//ray-casting to the right
bool Point::isInPolygon(std::vector<int> &xPoints, std::vector<int> &yPoints)
{
    int i, j = 0;
    bool c = false;
    int nvert = xPoints.size();

    for (i = 0, j = nvert-1; i < nvert; j = i++)
    {
        if ( ((yPoints[i]>this->y) != (yPoints[j]>this->y)) &&
             (this->x < (xPoints[j]-xPoints[i]) * (this->y-yPoints[i]) / (yPoints[j]-yPoints[i]) + xPoints[i]) )
            c = !c;
    }
    return c;
}

SDL_Point *Point::toSDL()
{
    SDL_Point* p = new SDL_Point;
    p->x = this->x;
    p->y = this->y;
    return p;
}

double Point::getAngle()//angulo em radianos
{
    return atan2(this->y, this->x);
}

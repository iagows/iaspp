#include "vector2d.h"

Vector2D::Vector2D():Object()
{
    this->x = 0;
    this->y = 0;
}

Vector2D::Vector2D(double x, double y):Object()
{
    this->x = x;
    this->y = y;
}

Vector2D::~Vector2D()
{

}

Vector2D Vector2D::operator+(const Vector2D &right)
{
    Vector2D vec;
    vec.x = this->x + right.x;
    vec.y = this->y + right.y;
    return vec;
}

Vector2D Vector2D::operator-(const Vector2D &right)
{
    Vector2D vec;
    vec.x = this->x - right.x;
    vec.y = this->y - right.y;
    return vec;
}

Vector2D Vector2D::operator*(const Vector2D &right)
{
    Vector2D vec;
    vec.x = this->x * right.x;
    vec.y = this->y * right.y;
    return vec;
}

Vector2D Vector2D::operator*(const double &right)
{
    Vector2D vec;
    vec.x = this->x * right;
    vec.y = this->y * right;
    return vec;
}

Vector2D Vector2D::operator/(const Vector2D &right)
{
    Vector2D vec;
    vec.x = this->x / right.x;
    vec.y = this->y / right.y;
    return vec;
}

Vector2D Vector2D::operator/(const double &right)
{
    Vector2D vec;
    vec.x = this->x / right;
    vec.y = this->y / right;
    return vec;
}

bool Vector2D::operator==(const Vector2D &right)
{
    return (this->x == right.x) && (this->y == right.y);
}

double Vector2D::dot(const Vector2D &right)
{
    return ((this->x * right.x) + (this->y * right.y));
}

double Vector2D::cross(const Vector2D &right)
{
    return ((this->x * right.y) - (this->y * right.x));
}

double Vector2D::length()
{
    return sqrt(squaredLenght());
}

double Vector2D::squaredLenght()
{
    return (this->x*this->x)+(this->y*this->y);
}

Vector2D Vector2D::unit()
{
    Vector2D vec;
    vec.x = this->x;
    vec.y = this->y;

    return vec/this->length();
}

Vector2D Vector2D::turnLeft()
{
    Vector2D vec(this->y, -this->x);
    return vec;
}

Vector2D Vector2D::turnRight()
{
    Vector2D vec(-this->y, this->x);
    return vec;
}

Vector2D Vector2D::rotate(double angle)
{
    Vector2D vec;
    double x_ = this->x*cos(angle)-this->y*sin(angle);
    double y_ = this->x*sin(angle)+this->y*cos(angle);
    vec.x = x_;
    vec.y = y_;
    return vec;
}

double Vector2D::angle()
{
    return atan2(this->y, this->x);
}

double Vector2D::distance(Vector2D &a, Vector2D &b)
{
    return (a-b).length();
}

Vector2D Vector2D::interpolate(Vector2D &p0, Vector2D &p1, double t)
{
    Vector2D p = (p0 *(1-t)) + (p1 * t);
    return p;
}

Vector2D Vector2D::rotateAroundPivot(Vector2D &p, Vector2D &pivot, double angle)
{
    return (p - pivot).rotate(angle) + pivot;
}

std::string Vector2D::toString()
{
    return "x: " + std::to_string(this->x) + " y: " + std::to_string(this->y) + ".";
}

Vector2D *Vector2D::clone()
{
    return new Vector2D(x, y);
}

Vector2D Vector2D::clone(const Vector2D &b)
{
    Vector2D vec(b.x, b.y);
    return vec;
}

void Vector2D::copyFrom(const Vector2D &b)
{
    this->x = b.x;
    this->y = b.y;
}

Vector2D Vector2D::normalize(const double v)
{
    return this->unit() * v;
}

Vector2D Vector2D::offset(double dx, double dy)
{
    Vector2D vec(this->x+dx, this->y+dy);
    return vec;
}

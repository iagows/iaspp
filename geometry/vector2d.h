#ifndef VECTOR_H
#define VECTOR_H

#include "object.h"
#include <math.h>

class IASPP_PUBLIC Vector2D : public Object
{
public:
    //bastante parecido com Point, mas especificamente vetor e com dupla precisão
    Vector2D();
    Vector2D(double x, double y);
    virtual ~Vector2D();

    double x;
    double y;

    Vector2D operator+(const Vector2D& right);
    Vector2D operator-(const Vector2D& right);
    Vector2D operator*(const Vector2D& right);
    Vector2D operator*(const double& right);
    Vector2D operator/(const Vector2D& right);
    Vector2D operator/(const double& right);
    bool operator==(const Vector2D& right);

    double dot(const Vector2D& right);//produto escalar
    double cross(const Vector2D& right);
    double length();
    double squaredLenght();
    Vector2D unit();

    Vector2D turnLeft();
    Vector2D turnRight();
    Vector2D rotate(double angle);
    double angle();

    static double distance(Vector2D &a, Vector2D& b);
    static Vector2D interpolate(Vector2D& a, Vector2D& b, double value);
    Vector2D rotateAroundPivot(Vector2D& p, Vector2D& pivot, double angle);

    virtual std::string toString() override;
    Vector2D* clone();
    Vector2D clone(const Vector2D& b);

    void copyFrom(const Vector2D& b);
    Vector2D normalize(const double v);
    Vector2D offset(double dx, double dy);
};

#endif // VECTOR_H

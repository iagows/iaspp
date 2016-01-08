#ifndef SOUNDPROPERTIES_H
#define SOUNDPROPERTIES_H

#include "object.h"

class IASPP_PUBLIC SoundProperties : public Object
{
public:
    SoundProperties();
    SoundProperties(double volume, double panning);
    virtual ~SoundProperties();

    double getLeftToLeft();
    void setLeftToLeft(double v);
    double getLeftToRight();
    void setLeftToRight(double v);

    double panning;

    double getRightToLeft();
    void setRightToLeft(double v);
    double getRightToRight();
    void setRightToRight(double v);

    double volume;

private:
    double left;
    double right;
    //está estéreo
    //colocar 4.0
    //colocar 5.1
};

#endif // SOUNDPROPERTIES_H

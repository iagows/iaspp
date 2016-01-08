#include "soundproperties.h"

SoundProperties::SoundProperties():Object()
{
    this->volume = 0;
    this->panning = 0;
}

SoundProperties::SoundProperties(double volume, double panning)
{
    this->volume = volume;
    this->panning = panning;
}

SoundProperties::~SoundProperties()
{

}

double SoundProperties::getLeftToLeft()
{
    return this->left;
}

void SoundProperties::setLeftToLeft(double v)
{
    this->left = v;
}

double SoundProperties::getLeftToRight()
{
    return 1-this->left;
}

void SoundProperties::setLeftToRight(double v)
{
    this->left = 1-v;
}

double SoundProperties::getRightToLeft()
{
    return 1-this->right;
}

void SoundProperties::setRightToLeft(double v)
{
    this->right = 1-v;
}

double SoundProperties::getRightToRight()
{
    return this->right;
}

void SoundProperties::setRightToRight(double v)
{
    this->right = v;
}

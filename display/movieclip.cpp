#include "movieclip.h"

MovieClip::MovieClip()
{
    this->currentFrame = -1;
    this->currentLabel = "";
    this->frames = new std::vector<MovieClip*>();
    this->labels = new std::vector<std::string>();
    this->isPlaying = true;
}

MovieClip::~MovieClip()
{
    for(size_t i=0; i<this->frames->size(); ++i)
    {
        MovieClip* mc = this->frames->at(i);
        delete mc;
    }
    this->frames->clear();
    this->labels->clear();
    delete this->frames;
    delete this->labels;
}

int MovieClip::getCurrentFrame()
{
    return this->currentFrame;
}

std::string MovieClip::getCurrentLabel()
{
    return this->labels->at(this->currentFrame);
}

bool MovieClip::getIsPlaying()
{
    return this->isPlaying;
}

int MovieClip::getTotalFrames()
{
    return this->frames->size();
}

void MovieClip::gotoAndPlay(std::string frame)
{

}

void MovieClip::gotoAndPlay(int frame)
{

}

void MovieClip::gotoAndStop(std::string frame)
{

}

void MovieClip::gotoAndStop(int frame)
{

}

void MovieClip::nextFrame()
{

}

void MovieClip::play()
{

}

void MovieClip::prevFrame()
{

}

void MovieClip::stop()
{

}

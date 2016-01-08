#ifndef MOVIECLIP_H
#define MOVIECLIP_H

#include "display/sprite.h"

class IASPP_PUBLIC MovieClip : public Sprite
{
public:
    MovieClip();
    virtual ~MovieClip();

    int getCurrentFrame();
    std::string getCurrentLabel();
    bool getIsPlaying();
    int getTotalFrames();

    void gotoAndPlay(std::string frame);
    void gotoAndPlay(int frame);
    void gotoAndStop(std::string frame);
    void gotoAndStop(int frame);
    void nextFrame();
    void play();
    void prevFrame();
    void stop();

private:
    std::vector<MovieClip*>* frames;
    std::vector<std::string>* labels;
    int currentFrame;
    std::string currentLabel;
    bool isPlaying;
};

#endif // MOVIECLIP_H

#include "stage.h"

Stage::Stage():DisplayableContainer()
{
    this->setColor(SDL_Color());
    this->frameRate = 30;
    this->setMouseLock(
            #ifdef DEBUG
                false
            #else
                true
            #endif
                );
    this->setScaleMode(StageScaleMode::NO_SCALE);
}

Stage::Stage(SDL_Color color, int frameRate, bool mouseLock, Stage::StageScaleMode mode)
{
    this->setColor(color);
    this->frameRate = frameRate;
    this->setMouseLock(mouseLock);
    this->setScaleMode(mode);
}

Stage::~Stage()
{

}

void Stage::setScaleMode(Stage::StageScaleMode mode)
{
    this->scaleMode = mode;
    //TODO: ver modo e modificar tela
}

void Stage::setColor(SDL_Color color)
{
    this->color = color;
    SDL_SetRenderDrawColor(this->renderer,
                           this->color.r,
                           this->color.g,
                           this->color.b,
                           this->color.a);
}

void Stage::setMouseLock(bool lock)
{
    this->mouseLock = lock;
    //https://gamedev.stackexchange.com/questions/33519/trap-mouse-in-sdl
    SDL_SetRelativeMouseMode(lock ? SDL_TRUE : SDL_FALSE); //SDL_MOUSEMOTION
}

void Stage::createChildren()
{

}

void Stage::setRenderer(SDL_Renderer* r)
{
    DisplayableContainer::setRenderer(r);
    this->setColor(this->color);
}

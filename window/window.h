#ifndef WINDOW_H
#define WINDOW_H

#include "display/displayablecontainer.h"
#include "display/stage.h"
#include "events/eventprocesser.h"

#include "window/windowenums.h"

class IASPP_PUBLIC Window : public DisplayableContainer
{
public:
    Window();
    Window(std::string title, Point* size,
           WindowEnums::WindowPosition horizontal = WindowEnums::WindowPosition::CENTERED,
           WindowEnums::WindowPosition vertical = WindowEnums::WindowPosition::CENTERED,
           Uint32 flags = WindowEnums::WindowFlags::SHOWN);
    virtual ~Window();
    bool alwaysInFront;
    bool maximizable;
    //menu
    bool minimizable;
    bool resizeable;
    void setTitle(std::string title);

    virtual bool createAndOpen();
    virtual void createChildren();
    //https://stackoverflow.com/questions/19311609/how-do-i-set-window-titlebar-icon-and-alt-tab-icon-in-sdl2-c-visual-studio
    bool setIcon(std::string icon);//true se conseguir
    void close();
    void maximize();
    void minimize();
    void restore();

    SDL_Renderer* getRenderer();

    virtual bool draw();
    virtual void createStage()=0;
protected:
    virtual bool update();
    virtual void processEvents();

    virtual void onClose();
    virtual void onLostFocus();
    virtual void onMaximize();
    virtual void onMinimize();
    virtual void onRegainFocus();
    virtual void onResize();
    virtual void onRestore();

private:
    SDL_Window *window;
    SDL_Surface *icon;

    std::string title;

    bool keepRunning;

    WindowEnums::WindowPosition horizontalPosition;
    WindowEnums::WindowPosition verticalPosition;
    Uint32 flags;
};

#endif // WINDOW_H

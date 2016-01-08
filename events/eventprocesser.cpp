#include "eventprocesser.h"

EventProcesser* EventProcesser::Instance()
{
    if(instance== nullptr)
        instance = new EventProcesser();

    return instance;
}

EventProcesser::~EventProcesser()
{
    delete instance;
}

bool EventProcesser::processEvents()
{
    bool output = true;
    while(SDL_PollEvent(&event))
    {
        //se o usuário fechou a janela
        if (event.type == SDL_QUIT)
        {
            output = false;
        }
        else
        {
            if(event.type == SDL_WINDOWEVENT)
            {
                processWindowEvents(&event);
            }

            switch (event.type) {
            case SDL_KEYDOWN:
            case SDL_KEYUP:
                this->dispatchKeyEvent(&event);
                break;
            case SDL_MOUSEMOTION:
                this->dispatchMouseMoveEvent(&event);
                break;
            case SDL_MOUSEBUTTONDOWN:
            case SDL_MOUSEBUTTONUP:
                this->dispatchMouseButtonEvent(&event);
                break;
            case SDL_MOUSEWHEEL:
                this->dispatchMouseWheelEvent(&event);
                break;
            default:
                break;
            }
        }
    }
    return output;
}

EventProcesser::EventProcesser():Object()
{
    this->lastMouseDown = 0;
    this->lastMouseMiddleDown = 0;
    this->lastMouseRightDown = 0;
    this->clickCount = 0;
}

void EventProcesser::processWindowEvents(const SDL_Event *evt)
{
    std::string type = "";
    Vector2D* to = nullptr;
    switch (evt->window.event)
    {
    case SDL_WINDOWEVENT_SHOWN:
        type = WindowEvent::SHOWN;
        break;
    case SDL_WINDOWEVENT_HIDDEN:
        type = WindowEvent::HIDDEN;
        break;
    case SDL_WINDOWEVENT_EXPOSED:
        type = WindowEvent::EXPOSED;
        break;
    case SDL_WINDOWEVENT_MOVED:
        type = WindowEvent::MOVED;
        to = new Vector2D(evt->window.data1, evt->window.data2);
        break;
    case SDL_WINDOWEVENT_RESIZED:
        type = WindowEvent::RESIZED;
        to = new Vector2D(evt->window.data1, evt->window.data2);
        break;
    case SDL_WINDOWEVENT_MINIMIZED:
        type = WindowEvent::MINIMIZED;
        break;
    case SDL_WINDOWEVENT_MAXIMIZED:
        type = WindowEvent::MAXIMIZED;
        break;
    case SDL_WINDOWEVENT_RESTORED:
        type = WindowEvent::RESTORED;
        break;
    case SDL_WINDOWEVENT_ENTER:
        type = WindowEvent::ENTER;
        break;
    case SDL_WINDOWEVENT_LEAVE:
        type = WindowEvent::LEAVE;
        break;
    case SDL_WINDOWEVENT_FOCUS_GAINED:
        type = WindowEvent::FOCUS_GAINED;
        break;
    case SDL_WINDOWEVENT_FOCUS_LOST:
        type = WindowEvent::FOCUS_LOST;
        break;
    case SDL_WINDOWEVENT_CLOSE:
        type = WindowEvent::CLOSE;
        break;
    }
}

void EventProcesser::dispatchKeyEvent(const SDL_Event *e)
{
    bool isDown = e->type == SDL_KEYDOWN;
    std::string type = isDown ? KeyboardEvent::KEY_DOWN : KeyboardEvent::KEY_UP;
    bool bubbles = true;
    bool cancelable = false;
    char charC = e->key.keysym.sym;
    size_t keyC = e->key.keysym.sym;
    bool ctrl = e->key.keysym.mod & (KMOD_LCTRL | KMOD_RCTRL);
    bool alt = e->key.keysym.mod & (KMOD_LALT | KMOD_RALT);
    bool shift = e->key.keysym.mod & (KMOD_LSHIFT | KMOD_RSHIFT);

    //, bool ctrlKeyValue=false,bool altKeyValue=false, bool shiftKeyValue=false);
    KeyboardEvent* ke = new KeyboardEvent(type,
                                          bubbles,
                                          cancelable,
                                          charC,
                                          keyC,
                                          ctrl,
                                          alt,
                                          shift);
    MainDispatcher::Instance()->dispatchEvent(dynamic_cast<Event*>(ke));
}

void EventProcesser::dispatchMouseMoveEvent(const SDL_Event *e)
{
    std::string type = MouseEvent::MOUSE_MOVE;
    const SDL_MouseMotionEvent mme = e->motion;
    int localX = mme.x;
    int localY = mme.y;
    int mX = mme.xrel;
    int mY = mme.yrel;

    bool buttonDown = SDL_GetMouseState(NULL, NULL)&SDL_BUTTON(1);

    MouseEvent* me = new MouseEvent(type, true, false, localX, localY, mX, mY,
                                    nullptr, false, false, false, buttonDown);
    MainDispatcher::Instance()->dispatchEvent(dynamic_cast<Event*>(me));
}

void EventProcesser::dispatchMouseButtonEvent(const SDL_Event *e)
{
    std::string type = "";

    const SDL_MouseButtonEvent mbe = e->button;
    const Uint8 *keys = SDL_GetKeyboardState(NULL);

    Uint8 bt = mbe.button;
    Uint32 ts = mbe.timestamp;

    bool clickLeft = false;
    bool clickMiddle = false;
    bool clickRight = false;
    bool down = false;
    if(mbe.type == SDL_MOUSEBUTTONDOWN)
    {
        down = true;
        if(bt == SDL_BUTTON_LEFT)
        {
            this->lastMouseDown = ts;
            type = MouseEvent::MOUSE_DOWN;
        }
        else if(bt == SDL_BUTTON_MIDDLE)
        {
            this->lastMouseMiddleDown = ts;
            type = MouseEvent::MIDDLE_MOUSE_DOWN;
        }
        else if(bt == SDL_BUTTON_RIGHT)
        {
            this->lastMouseRightDown = ts;
            type = MouseEvent::RIGHT_MOUSE_DOWN;
        }
    }
    else if(mbe.type == SDL_MOUSEBUTTONUP)
    {
        if(bt == SDL_BUTTON_LEFT)
        {
            Uint32 dt = ts - lastMouseDown;
            clickLeft = dt < diff;
            type = MouseEvent::MOUSE_UP;
            if(clickLeft)
            {
                if(clickCount == 0)
                {
                    clickCount++;
                }
                else if(clickCount == 1)
                {
                    clickCount++;
                }
            }
            else
                clickCount = 0;
        }
        else if(bt == SDL_BUTTON_MIDDLE)
        {
            Uint32 dt = ts - lastMouseMiddleDown;
            clickMiddle = dt < diff;
            type = MouseEvent::MIDDLE_MOUSE_UP;
        }
        else if(bt == SDL_BUTTON_RIGHT)
        {
            Uint32 dt = ts - lastMouseRightDown;
            clickRight = dt < diff;
            type = MouseEvent::RIGHT_MOUSE_UP;
        }
    }

    bool ctrlKey = keys[SDL_SCANCODE_LCTRL] || keys[SDL_SCANCODE_RCTRL];
    bool altKey = keys[SDL_SCANCODE_LALT] || keys[SDL_SCANCODE_RALT];
    bool shiftKey = keys[SDL_SCANCODE_LSHIFT] || keys[SDL_SCANCODE_RSHIFT];

    MouseEvent* me = new MouseEvent(type, true, false, 0, 0, 0, 0, nullptr, ctrlKey, altKey, shiftKey, down);

    if(clickLeft)
    {
        type = MouseEvent::CLICK;
    }
    else if(clickMiddle)
    {
        type = MouseEvent::MIDDLE_CLICK;
    }
    else if(clickRight)
    {
        type = MouseEvent::RIGHT_CLICK;
    }

    MouseEvent* meClick = new MouseEvent(type, true, false, 0,0,0,0,nullptr, ctrlKey, altKey, shiftKey, false);

    MainDispatcher::Instance()->dispatchEvent(dynamic_cast<Event*>(me));
    MainDispatcher::Instance()->dispatchEvent(dynamic_cast<Event*>(meClick));

    if(clickCount == 2)
    {
        type = MouseEvent::DOUBLE_CLICK_;
        this->clickCount = 0;
        MouseEvent* meDouble = new MouseEvent(type, true, false, 0,0,0,0, nullptr, ctrlKey, altKey, shiftKey, false);
        MainDispatcher::Instance()->dispatchEvent(dynamic_cast<Event*>(meDouble));
    }
}

void EventProcesser::dispatchMouseWheelEvent(const SDL_Event *e)
{

}

EventProcesser* EventProcesser::instance = nullptr;

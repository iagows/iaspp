#include "window.h"

Window::Window():DisplayableContainer()
{
    this->icon = nullptr;
    this->title = "IGL";
    this->width = 800;
    this->height = 600;
    this->horizontalPosition = WindowEnums::WindowPosition::CENTERED;
    this->verticalPosition = WindowEnums::WindowPosition::CENTERED;
    this->flags = WindowEnums::WindowFlags::SHOWN;
}

Window::Window(std::string title, Point *size, WindowEnums::WindowPosition horizontal, WindowEnums::WindowPosition vertical,
               Uint32 flags)
{
    this->title = title;
    this->width = size->x;
    this->height = size->y;
    this->horizontalPosition = horizontal;
    this->verticalPosition = vertical;
    this->flags = flags;
    this->icon = nullptr;
}


Window::~Window()
{
    if(this->window!=nullptr)
        SDL_DestroyWindow(this->window);
    if(this->icon!=nullptr)
        SDL_FreeSurface(this->icon);

    if(this->renderer!=nullptr)
        SDL_DestroyRenderer(this->renderer);
}

void Window::setTitle(std::string title)
{
    //atualiza a variável
    this->title = title;
    //muda título na janela
    SDL_SetWindowTitle(this->window, this->title.c_str());
}

bool Window::createAndOpen()
{
    this->keepRunning = true;
    this->window = SDL_CreateWindow(this->title.c_str(), SDL_WINDOWPOS_CENTERED,
            SDL_WINDOWPOS_CENTERED, this->width, this->height, this->flags);

    this->renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
    this->createStage();
    return this->renderer != nullptr;
}

void Window::createChildren()
{

}

bool Window::setIcon(std::string icon)
{
    if(this->icon != nullptr)
    {
        SDL_FreeSurface(this->icon);
    }

    //TODO fazer a troca

}

void Window::close()
{
    SDL_DestroyWindow(this->window);
}

void Window::maximize()
{
    SDL_MaximizeWindow(this->window);
}

void Window::minimize()
{
    SDL_MinimizeWindow(this->window);
}

void Window::restore()
{
    SDL_RestoreWindow(this->window);
}

bool Window::update()
{
    int start;
    //Draw the images
    while(this->keepRunning)
    {
        start = SDL_GetTicks();
        //Rendering
        SDL_RenderClear(this->renderer);
        if(this->renderer == nullptr) continue;
        this->processEvents();
        for(Displayable *d : *(this->children))
        {
            if(!d->draw())
            {
                this->keepRunning = false;
#ifdef DEBUG
                aspp::trace("Error at update().", "Arquivo:", d->toString());
#endif
            }
        }
        //Update the screen
        SDL_RenderPresent(this->renderer);
    }
    return true;
}

void Window::processEvents()
{
    if(!EventProcesser::Instance()->processEvents())
    {
        this->onClose();
    }
}

void Window::onClose()
{
    this->keepRunning = false;
}

void Window::onLostFocus()
{

}

void Window::onMaximize()
{

}

void Window::onMinimize()
{

}

void Window::onRegainFocus()
{

}

void Window::onResize()
{
    SDL_GetWindowSize(this->window, &this->width, &this->height);
}

void Window::onRestore()
{

}

SDL_Renderer *Window::getRenderer()
{
    return this->renderer;
}

bool Window::draw()
{
    return this->update();
}

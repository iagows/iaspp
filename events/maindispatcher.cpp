#include "maindispatcher.h"

MainDispatcher *MainDispatcher::Instance()
{
    if(instance == nullptr)
        instance = new MainDispatcher();

    return instance;
}

MainDispatcher::~MainDispatcher()
{
    delete instance;
}

MainDispatcher::MainDispatcher():EventDispatcher()
{
}

MainDispatcher* MainDispatcher::instance = nullptr;

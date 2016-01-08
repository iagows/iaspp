#ifndef EVENT_H
#define EVENT_H

#include "object.h"

class IASPP_PUBLIC Event : public Object
{
public:
    Event(std::string type, bool bubbles = false, bool cancelable = false);
    virtual ~Event();

    virtual bool bubbles() final;

    virtual bool cancelable() final;

    virtual Object* currentTarget() final;

    virtual size_t eventPhase() final;

    Object* getTarget();

    void setTarget(Object* target);

    virtual std::string type() final;

    virtual Event* clone();

    //Uma função de utilitário para implementar o método toString() em classes ActionScript 3.0 Event personalizadas.
    //virtual std::string formatToString(std::string className, ... arguments)

    //Verifica se o método preventDefault() foi chamado no evento.
    virtual bool isDefaultPrevented();

    //Cancela um comportamento padrão de evento se esse comportamento puder ser cancelado.
    virtual void preventDefault();

    //Impede o processamento de qualquer ouvinte de evento no nó atual e qualquer nó subsequente no fluxo de eventos.
    virtual void stopImmediatePropagation();

    //Impede o processamento de algum ouvinte de evento em nós subsequentes ao nó atual no fluxo de eventos.
    virtual void stopPropagation();

    //Retorna uma string que contém todas as propriedades do objeto Event.
    virtual std::string toString();

    const static std::string ACTIVATE;
    const static std::string ADDED;
    const static std::string ADDED_TO_STAGE;
    const static std::string CANCEL;
    const static std::string CHANGE;
    const static std::string CLEAR;
    const static std::string CLOSE;
    const static std::string CLOSING;
    const static std::string COPY;
    const static std::string CUT;
    const static std::string DEACTIVATE;
    const static std::string ENTER_FRAME;
    const static std::string EXIT_FRAME;
    const static std::string FRAME_CONSTRUCTED;
    const static std::string FULLSCREEN;
    const static std::string INIT;
    const static std::string MOUSE_LEAVE;
    const static std::string OPEN;
    const static std::string PASTE;
    const static std::string REMOVED;
    const static std::string REMOVED_FROM_STAGE;
    const static std::string RENDER;
    const static std::string RESIZE;
    const static std::string SUSPEND;
    const static std::string TAB_CHILDREN_CHANGE;
    const static std::string TAB_ENABLED_CHANGE;
    const static std::string TAB_INDEX_CHANGE;
    const static std::string USER_IDLE;
    const static std::string USER_PRESENT;

protected:
    bool _bubbles;
    bool _cancelable;
    Object* _currentTarget;
    size_t _eventPhase;
    Object* _target;
    std::string _type;
};

#endif // EVENT_H

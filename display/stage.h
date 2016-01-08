#ifndef STAGE_H
#define STAGE_H

#include "display/displayablecontainer.h"
class IASPP_PUBLIC Stage : public DisplayableContainer
{
public:
    enum StageScaleMode
    {
        //O aplicativo inteiro está visível na área especificada sem tentar
        //preservar a proporção original. Podem ocorrer distorções e o
        //aplicativo pode parecer ampliado ou compactado.
        EXACT_FIT,
        //O aplicativo inteiro está visível na área especificada sem distorções,
        //mantendo a proporção original do aplicativo. As bordas podem aparecer
        //nos dois lados do aplicativo.
        SHOW_ALL,
        //O aplicativo inteiro preenche a área especificada, sem distorções,
        //mas possivelmente com um certo nível de corte, mantendo ao mesmo
        //tempo a proporção original do aplicativo.
        NO_BORDER,
        //O aplicativo inteiro é fixo, permanecendo inalterado mesmo que haja
        //uma alteração no tamanho da janela do player. Poderão ocorrer cortes
        //se a janela do player for menor do que o conteúdo.
        NO_SCALE

    };
    Stage();
    Stage(SDL_Color color, int frameRate = 30, bool mouseLock =
        #ifdef DEBUG
            false
        #else
            true
        #endif
            , StageScaleMode mode = StageScaleMode::NO_SCALE);

    virtual ~Stage();

    int frameRate;

    void setScaleMode(StageScaleMode mode);
    void setColor(SDL_Color color);
    void setMouseLock(bool lock);

    virtual void createChildren();

    virtual void setRenderer(SDL_Renderer *r);

private:
    StageScaleMode scaleMode;
    bool mouseLock;
    SDL_Color color;
};

#endif // STAGE_H

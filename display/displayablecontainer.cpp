#include "displayablecontainer.h"

DisplayableContainer::DisplayableContainer():Interactive()
{

}

DisplayableContainer::~DisplayableContainer()
{

}

size_t DisplayableContainer::getNumChildren()
{
    return this->children->size();
}

void DisplayableContainer::addChild(Displayable *child)
{
    if(this == child)
    {
        //lança erro se o filho for igual ao pai
        throw;
    }
    //adiciona
    this->children->push_back(child);

    //avisa quem é o novo pai
    child->setParent(this);

    //se tiver outro pai, remove
    this->removeFromParent(child);

    //lança evento "added"
    //TODO : lançar evento
}

void DisplayableContainer::addChildAt(Displayable *child, size_t index)
{
    if(this == child)
    {
        //lança erro se o filho for igual ao pai
        throw;
    }
    if(index > this->getNumChildren())
    {
        //lança erro se o índice estiver fora dos limites
        throw;
    }

    //adiciona
    this->children->insert(this->children->begin()+index, child);

    //adiciona
    this->children->push_back(child);

    //se tiver outro pai, remove
    this->removeFromParent(child);

    //lança evento "added"
    //TODO : lançar evento
}

bool DisplayableContainer::contains(Displayable *child)
{
    //se é filho ou se é esse próprio objeto
    bool is = false;
    if(child == this)
    {
        is = true;
    }
    else
    {
        /*for(size_t i=0; i<this->children->size(); ++i)
        {
            if(child == this->children->at(i))
            {
                is = true;
                break;
            }
        }*/
        for(Displayable *d : *(this->children))
        {
            if(d == child)
            {
                is = true;
                break;
            }
        }
    }

    return is;
}

Displayable *DisplayableContainer::getChildAt(size_t index)
{
    Displayable* at = nullptr;
    if(index < this->children->size())
    {
        at = this->children->at(index);
    }
    return at;
    //retorna ponteiro nulo caso dê merda
}

Displayable *DisplayableContainer::getChildByName(std::string name_)
{
    Displayable* byName = nullptr;

    for(Displayable * d : *(this->children))
    {
        if(d->name == name_)
        {
            byName = d;
            break;
        }
    }
    /*for(size_t i=0; i<this->children->size(); ++i)
    {
        Displayable* temp = this->children->at(i);
        if(temp->name == name_)
        {
            byName = temp;
            break;
        }
    }*/

    return byName;
}

int DisplayableContainer::getChildIndex(Displayable *child)
{
    int out = -1;
    for(size_t i=0; i<this->children->size(); ++i)
    {
        Displayable* temp = this->children->at(i);
        if(temp == child)
        {
            out = i;
            break;
        }
    }
    return out;
}

std::vector<Displayable *> *DisplayableContainer::getObjectsUnderPoint(Point *p)
{
    std::vector<Displayable*>* out = new std::vector<Displayable*>();
    //retorna os filhos sob esse ponto
    /*for(size_t i=0; i<this->children->size(); ++i)
    {
        Displayable* d = this->children->at(i);
        Rectangle* r = d->getRectangle();

        std::vector<int> *x_ = r->xVectors();
        std::vector<int> *y_ = r->yVectors();
        if(p->isInPolygon(*x_, *y_))
        {
            out->push_back(d);
        }
        delete y_;
        delete x_;
        delete r;
    }*/
    for(Displayable *d : *(this->children))
    {
        Rectangle* r = d->getRectangle();

        std::vector<int> *x_ = r->xVectors();
        std::vector<int> *y_ = r->yVectors();
        if(p->isInPolygon(*x_, *y_))
        {
            out->push_back(d);
        }
        delete y_;
        delete x_;
        delete r;
    }
    return out;
}

void DisplayableContainer::removeChild(Displayable *child)
{
    this->removeFromChildren(child);
}

void DisplayableContainer::removeChildAt(size_t index)
{
    this->removeChildren(index, index+1);
}

void DisplayableContainer::removeChildren(size_t beginIndex, size_t endIndex)
{
    if((beginIndex>this->children->size()) || (endIndex > this->children->size()))
    {
        throw;
    }

    this->children->erase(this->children->begin()+beginIndex, this->children->begin()+endIndex);
}

void DisplayableContainer::setChildIndex(Displayable *child, size_t index)
{
    if(index > this->getNumChildren())
    {
        throw;
    }
    this->removeChild(child);
    this->addChildAt(child, index);
    //lança erro se não for filho
}

void DisplayableContainer::stopAllAnimations()
{
    //para todos os filhos
}

void DisplayableContainer::swapChildren(Displayable *a, Displayable *b)
{
    int indexA = this->getChildIndex(a);
    int indexB = this->getChildIndex(b);
    this->swapChildrenAt(indexA, indexB);
}

void DisplayableContainer::swapChildrenAt(int indexA, int indexB)
{
    //lança erro se um índice for inválido
    if(indexA > -1 && indexB > -1)
    {
        std::swap(this->children[indexA], this->children[indexB]);
    }
    else
    {
        //lança erro se não forem filhos
        throw;
    }
}

void DisplayableContainer::removeFromParent(Displayable *d)
{
    if(d->getParent() != nullptr && d->getParent() != this )
    {
        Displayable* p = d->getParent();
        p->removeFromChildren(d);
    }
}

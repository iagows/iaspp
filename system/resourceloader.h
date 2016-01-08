#ifndef RESOURCELOADER_H
#define RESOURCELOADER_H

#include <vector>

#include "object.h"
#include "system/file.h"

template<typename T>
class IAGOGAMELIBSHARED_EXPORT ResourceLoader : public Object
{
public:
    ResourceLoader(std::string folder);
    virtual ~ResourceLoader();

private:
    std::vector<T> *data;
    File *folder;

    void fillData();
};

ResourceLoader::ResourceLoader(std::string folder)
{
    this->data = new std::vector<T*>;
    this->folder = new File(File::getResourcePath(folder));
    if(this->folder->isDirectory())
    {

    }
    else
    {
        throw;
    }
}

ResourceLoader::~ResourceLoader()
{
    for(T* t : this->data)
    {
        delete t;
    }
    delete data;
    delete folder;
}

void ResourceLoader::fillData()
{

}

#endif // RESOURCELOADER_H

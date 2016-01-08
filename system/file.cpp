#include "file.h"
#include <string.h>

File::File():Object()
{
    this->path = "";
    this->name = "";
    this->type = "";
    this->size = 0;
    this->hidden = false;
    this->readOnly = false;

#ifdef WINDOWS
    this->setCurrentUser();
#endif
}

File::File(std::string path):Object()
{
    this->name = "";
    this->type = "";
    this->size = 0;
    this->hidden = false;
    this->readOnly = false;

    this->setPath(path);

#ifdef WINDOWS
    this->setCurrentUser();
#endif
}

File::~File()
{

}

std::string File::getName()
{
    return this->name;
}

size_t File::getSize()
{
    return this->size;
}

std::string File::getType()
{
    return this->type;
}

std::string File::getAppDirectory()
{
    return SDL_GetBasePath();
}

std::string File::getDesktop()
{
    std::string slash = File::SEPARATOR;
#ifdef WINDOWS
    return "C:"+slash + "Users"+slash + File::currentUser + slash + "Desktop";
#else
    return "~/Desktop";
#endif
}

std::string File::getDocuments()
{
    std::string slash = File::SEPARATOR;
#ifdef WINDOWS
    return "C:"+slash + "Users"+slash + File::currentUser + slash + "Documents";
#else
    return "~/Documents";
#endif
}

std::string File::getUserDirectory()
{
    std::string slash = File::SEPARATOR;
#ifdef WINDOWS
    return "C:"+slash + "Users"+slash + File::currentUser;
#else
    return "~";
#endif
}

std::string File::getGamesDirectory()
{
    std::string slash = File::SEPARATOR;
#ifdef WINDOWS
    return "C:"+slash + "Users"+slash + File::currentUser + slash + "Documents" + slash + "My Games";
#else
    return "~/Documents/Games";
#endif
}

bool File::exists()
{
    return File::exists(this->path);
}

//https://stackoverflow.com/questions/12774207/fastest-way-to-check-if-a-file-exist-using-standard-c-c11-c
bool File::exists(std::string p)
{
    struct stat buffer;
    return (stat(p.c_str(), &buffer)==0);
}

//https://stackoverflow.com/questions/146924/how-can-i-tell-if-a-given-path-is-a-directory-or-a-file-c-c
bool File::isDirectory()
{
    bool out = false;
    struct stat s;
    if( stat(this->path.c_str(),&s) == 0 )
    {
        if( s.st_mode & S_IFDIR )
        {
            out = true;
        }
    }
    return out;
}

bool File::isHidden()
{
    bool out = false;
#ifdef WINDOWS
    //https://stackoverflow.com/questions/27220/how-to-convert-stdstring-to-lpcwstr-in-c-unicode
    std::wstring stemp = std::wstring(this->path.begin(), this->path.end());
    //https://stackoverflow.com/questions/1343635/checking-if-a-folder-file-is-hidden-system-in-windows-c-c
    DWORD attributes = GetFileAttributes(stemp.c_str());
    out = attributes & FILE_ATTRIBUTE_HIDDEN;
#else
    //http://stackoverflow.com/questions/14663548/c-program-to-list-hidden-and-read-only-files
    //starts with '.', but not only '.' nor '..'
    out = this->path[0] == '.' &&
            strcmp(this->path.c_str(), ".") != 0 &&
            strcmp(this->path.c_str(), "..") != 0;
#endif
    return out;
}

File *File::getParent()
{
    File *f = new File();
    if(!this->path.empty())
    {
        size_t find = this->path.find_last_of(File::SEPARATOR);
        f->setPath(this->path.substr(0, find));
    }
    return f;
}
/*
std::string File::getSystemCharSet()
{

}*/

//https://stackoverflow.com/questions/10195343/copy-a-file-in-an-sane-safe-and-efficient-way
void File::copyTo(std::string f, bool overwrite)
{
    if(overwrite || (!overwrite && !File::exists(f)))
    {
        std::ifstream src(this->path, std::ios::binary);
        std::ofstream dst(f, std::ios::binary);

        dst << src.rdbuf();
    }
}

void File::createDirectory()
{
    if(!File::exists(this->path))
    {
#ifdef WINDOWS
        mkdir(this->path.c_str());
#elif LINUX
        //"sudo"
        mode_t currentMask = umask(0);
        //creates the folder
        //Read Write Execute >> user, group, other
        mkdir(this->path.c_str(),  S_IRWXU | S_IRWXG | S_IRWXO);
        //ending "sudo"
        umask(currentMask);
#endif
    }
}

void File::deleteDirectory()
{
    //rmdir(this->path.c_str());
    aspp_throw("TO DO");
    throw;
}

void File::deleteFile()
{
    remove(this->path.c_str());
}

StringVector *File::getDirectoryListing()
{
    StringVector *sv = new StringVector();
    DIR *dir;
    struct dirent *ent;
    if((dir = opendir(this->path.c_str())) != nullptr)
    {
        while((ent = readdir(dir)) != nullptr)
        {
            std::string s = ent->d_name;
            if((strcmp(s.c_str(), ".") != 0) && (strcmp(s.c_str(), "..") != 0))
            {
                sv->push_back(s);
            }
        }
    }
    delete ent;
    delete dir;
    return sv;
}

std::string File::getRelativePath(std::string f)
{
    aspp_throw("TO DO");
    throw;
}

std::vector<File *> File::getRootDirectories()
{
    aspp_throw("TO DO");
    throw;
}

void File::moveTo(std::string f, bool overwrite)
{
    aspp_throw("TO DO");
    throw;
}

void File::moveToTrash()
{
    aspp_throw("TO DO");
    throw;
}

File *File::resolvePath()
{
    aspp_throw("TO DO");
    throw;
}

void File::setPath(std::string p)
{
    this->path = p;
    this->setName();

    this->setType();
    this->setSize();
}

std::string File::getPath()
{
    return this->path;
}

std::string File::getResourcePath(const std::string &subDir)
{
    //estático pra garantir que isso tudo só
    //vai rodar uma vez
    static std::string baseRes;
    if(baseRes.empty())
    {
        //retorna NULL no caso de merda
        char *basePath = SDL_GetBasePath();
        if(basePath)
        {
            baseRes = basePath;
            SDL_free(basePath);
        }
        else
        {
            return "";
        }

        size_t pos = baseRes.rfind("bin");
        baseRes = baseRes.substr(0,pos)+"resources"+ File::SEPARATOR;
    }
    return subDir.empty() ? baseRes:baseRes + subDir + File::SEPARATOR;
}

#ifdef WINDOWS
void File::setCurrentUser()
{
    if(File::currentUser.empty())
    {
        TCHAR username[UNLEN+1];
        DWORD username_len = UNLEN+1;
        if(GetUserName(username, &username_len))
        {
            int size_ = sizeof(username)/sizeof(*username);
            std::cout << "size: " << sizeof(username) << " " << sizeof(*username) << std::endl;
            File::currentUser = "";
            for(int i =0; i< size_; ++i)
            {
                wchar_t temp = username[i];
                if(temp == 0)
                    break;
                File::currentUser.push_back(username[i]);
            }
        }
    }
}

std::string File::currentUser = "";
#endif


void File::setName()
{
    this->name = "";
    if(!this->path.empty())
    {
        size_t i = this->path.find_last_of(File::SEPARATOR);
        if(i!= std::string::npos)
            this->name = this->path.substr(i+1);
    }
}

void File::setType()
{
    this->type = "";

    if(this->name.size() > 0)
    {
        size_t i = this->name.find_last_of(".");
        if(i != std::string::npos)
            this->type = this->name.substr(i, this->name.length()-1);
    }
}

void File::setSize()
{
    this->size = 0;
    struct stat st;
    if(stat(this->path.c_str(), &st) == 0)
    {
        this->size = st.st_size;
    }
}

#ifdef WINDOWS
    const std::string File::SEPARATOR = "\\";
    const std::string File::LINE_ENDING = "\r\n";
#else
    const std::string File::SEPARATOR = "/";
    const std::string File::LINE_ENDING = "\n";
#endif

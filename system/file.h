#ifndef FILE_H
#define FILE_H

#include "object.h"
#include "util/stringutil.h"
#include <vector>
#include <sys/stat.h>
#include <fstream>
#include <dirent.h>

#ifdef WINDOWS

    //don't let windows.h f*** with my Rectangle class :)
    //changing the name
    #define Rectangle winRectangle

    #include <windows.h>

    //changing back
    #undef Rectangle
    //if the Rectangle error remains, change Rectangle class to Rectangle_
#include <lmcons.h>
#endif
//TODO end coding

//http://help.adobe.com/pt_BR/FlashPlatform/reference/actionscript/3/flash/filesystem/File.html
class IASPP_PUBLIC File : Object
{
public:
    File();
    File(std::string path);
    virtual ~File();
    std::string getName();

    size_t getSize(); //size in bytes
    std::string getType();
    //bytearray data

    //http://qt-project.org/doc/qt-5/qstandardpaths.html
    static std::string getAppDirectory();
    static std::string getDesktop();
    static std::string getDocuments();
    static std::string getUserDirectory();
    static std::string getGamesDirectory();

    bool exists();
    static bool exists(std::string p);
    bool isDirectory();
    bool isHidden();
    bool isReadOnly();
    //bool isSymbolicLink();
    const static std::string LINE_ENDING;
    File *getParent();
    const static std::string SEPARATOR;
    //unsigned long int spaceAvailable();
    //std::string getSystemCharSet();

    void copyTo(std::string f, bool overwrite=true);
    void createDirectory();
    //File* createTempDirectory();
    //File* createTempFile();
    void deleteDirectory();
    void deleteFile();
    StringVector *getDirectoryListing();
    std::string getRelativePath(std::string f);
    std::vector<File *> getRootDirectories();
    void moveTo(std::string f, bool overwrite=false);
    void moveToTrash();
    File* resolvePath();

    void setPath(std::string p);
    std::string getPath();
    static std::string getResourcePath(const std::string &subDir = "");
#ifdef WINDOWS
    static std::string currentUser;
#endif

private:
    std::string path;
    std::string name;
    std::string type;
    size_t size;
    bool hidden;
    bool readOnly;

#ifdef WINDOWS
    void setCurrentUser();
#endif
    void setName();
    void setType();
    void setSize();
};

#endif // FILE_H

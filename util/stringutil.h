#ifndef STRINGUTIL_H
#define STRINGUTIL_H

#include "object.h"
#include <vector>

typedef std::vector<std::string> StringVector;

class IASPP_PUBLIC StringUtil : public Object
{
public:
    StringUtil();
    virtual ~StringUtil();

    static StringVector* split(std::string input, std::string token);
};

#endif // STRINGUTIL_H

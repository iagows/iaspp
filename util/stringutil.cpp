#include "stringutil.h"

StringUtil::StringUtil():Object()
{
}

StringUtil::~StringUtil()
{

}

StringVector *StringUtil::split(std::string input, std::string token)
{
    StringVector *sVec = new StringVector();
    size_t pos = 0;
    std::string tok;
    while((pos = input.find(token)) != std::string::npos)
    {
        tok = input.substr(0, pos);
        sVec->push_back(tok);
        input.erase(0, pos+token.size());
    }
    if(!input.empty())
        sVec->push_back(input);
    return sVec;
}

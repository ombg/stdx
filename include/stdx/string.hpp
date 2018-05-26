#ifndef _STDX_STRING_H_
#define _STDX_STRING_H_

#include <string>
#include <sstream>
#include <vector>

namespace stdx
{
    
static void splitString(const std::string &s, char delim, std::vector<std::string> &elems)
{
    std::stringstream ss(s);
    std::string item;
    while (std::getline(ss, item, delim))
    {
        if (item.size() == 0) continue;
        elems.push_back(item);
    }
}

static std::string toHexString(unsigned val)
{
    char tmphex[9];
    sprintf(tmphex, "%08x", val);
    return std::string(tmphex);
}
    
static unsigned fromHexString(std::string str)
{
    std::size_t dummy;
    return std::stoul(str, &dummy, 16);
}

static std::string eraseFileExtension(std::string fstr, std::string fstr_ext)
{    
    // check if no file extension
    // otherwise, delete fstr_ext
    size_t pos    = fstr.rfind(fstr_ext); 
    size_t dotpos = fstr.rfind(".");
    
    if(   pos != std::string::npos 
       && pos == dotpos)
    {
        // Erase file ext
        fstr.erase( fstr.end() - 4, fstr.end() );
    }
    else
    {
        printf("Warning: Could not delete file extension.\n");
    }
    return fstr;
}
    
} //stdx
#endif //_STDX_STRING_H_

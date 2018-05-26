//
//  scandir.h
//  imgdb
//
//  Created by Oliver Meynberg on 22/07/15.
//
//

#ifndef STDX_FILESYSTEM_HPP
#define STDX_FILESYSTEM_HPP

#include <string>
#include <vector>
#include <stdexcept>
#include <filesystem>

#if defined ( __APPLE__  ) || defined ( __linux__ ) 
#include <sys/dir.h>
#include <sys/dirent.h>
#include <sys/stat.h>
#elif defined ( _WIN32 )
#include <windows.h>
#endif // OS check

using namespace std;

namespace stdx
{
    
void getFiles(const string& in_folder, vector<string>& out_files)
{
#ifndef _WIN32
    DIR *dir;
    struct dirent *ent;
    if ((dir = opendir ( in_folder.c_str() )) != NULL)
    {
        //Loop through directory and push file names to vector.
        while ((ent = readdir (dir)) != NULL)
        {
            string basename = string(ent->d_name);
            out_files.push_back(in_folder + "/" + basename);
        }
        closedir (dir);
    } 
    else
    {
        //could not open directory
        throw std::invalid_argument
        ("Cannot open directory:\n" + in_folder);
    }
#else
#error "Oh no... Windows. Really?"
#endif //_WIN32
}

bool createDirectory(const char* newdir)
{
#if defined ( __APPLE__  ) || defined ( __linux__ ) 
    if( mkdir(newdir, 0755) == -1 )
#elif defined ( _WIN32 )
    if( !CreateDirectory(newdir, NULL ) )
#endif
    {
        return false;
    }
    else
    {
        return true;
    }
}
    
std::string basename(std::string str)
{
    // Remove directory if present.
    // Do this before extension removal incase directory has a period character.
    const size_t last_slash_idx = str.find_last_of("\\/");
    if (std::string::npos != last_slash_idx)
    {
        str.erase(0, last_slash_idx + 1);
    }
    
    // Remove extension if present.
    const size_t period_idx = str.rfind('.');
    if (std::string::npos != period_idx)
    {
        str.erase(period_idx);
    }
    return str;
}
std::string fileExt(const std::string& str)
{
    if(str.find_last_of(".") != std::string::npos)
        return str.substr(str.find_last_of(".")+1);
    return "";
}
bool fileExists(const std::string& str)
{
    return std::filesystem::exists(str);
}
} //stdx
#endif //#ifndef STDX_FILESYSTEM_HPP

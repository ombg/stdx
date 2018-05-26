#include <string>
#include <iostream>
#include <vector>
// include stdx string
#include "stdx/string.hpp"

int main(int argc, char* argv[])
{
    
    std::string instr = std::string(argv[1]);
    std::vector < std::string > splittedstr;
    
    //Call splitstring function
    stdx::splitString(instr,'_', splittedstr);
    
    for(auto &iter : splittedstr)
    {
        printf("%s\n",iter.c_str());
    }
    printf("=====\n");
    //Caution, only std::stoi takes care of none-numeric characters
    printf("%d\n",std::stoi(splittedstr.back().c_str()));
    printf("%s\n",(splittedstr.rbegin() + 1)->c_str());
    return 0;
}
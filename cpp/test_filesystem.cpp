#include <string>
#include <iostream>
#include "filesystem.hpp"

int main(int argc, char* argv[])
{
    bool result = stdx::fileExists(std::string("/Users/oliver/byobu-thesis.sh"));
    std::cout << result << std::endl;
    return 0;
}

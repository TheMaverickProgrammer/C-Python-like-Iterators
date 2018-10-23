/*
Author: Maverick Peppers
Date: 10/22/2018

Example file
See `Enumerate.h` for more info
*/

#include "Enumerate.h"
#include <iostream> 
#include <vector>
#include <map>
#include <string>

int main() {
    std::vector<int> test{1, 2, 3, 4, 5};
    f(test);
    g(test);
    
    std::map<std::string, int> map{{"a", 10}, {"b", 9},{"c", 7}, {"d", 8}};
    h(map);
}

int f(std::vector<int>& ints)
{
    int result = 0;

    size_t i = 0;
    for(auto iter = ints.begin(); iter != ints.end();)
    {
        result += i + *iter;
        ++i;
        ++iter;
    }

    return result;
}

int g(std::vector<int>& ints)
{
    int result = 0;

    for(const auto& [i, n] : enumerate(ints))
    {
        result += i + n;
        ++n;
    }

    return result;
}


int h(std::map<std::string, int>& map)
{
    int result = 0;

    for(auto i : enumerate(map))
    {
        // i will be type std::string
        std::cout << "index: " << i << std::endl;
    }

    return result;
}

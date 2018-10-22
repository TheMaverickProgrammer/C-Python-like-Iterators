/*
Author: Maverick Peppers
Date: 10/22/2018

Example file
See `Enumerate.h` for more info
*/

#include "Enumerate.h"

int main() {
    std::vector<int> test{1, 2, 3, 4, 5};
    
    f(test);
    g(Test);
    h(test);
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


int h(std::vector<int>& ints)
{
    int result = 0;

    for(int i : enumerate(ints))
    {
        result += i;
    }

    return result;
}

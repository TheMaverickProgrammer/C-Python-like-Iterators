# C-Python-like-Iterators
Header only and using modern C++ 17 and templates, provides a function `enumerate` that easily returns key-value pairs for any standard container type as seen in the Python programming language.

# Minimal Working Example
```
#include "Enumerate.h"
#include <iostream>
#include <vector>
#include <map>
#include <string>

int main(char** argv, int argc) {
    std::vector<int> myVec({10,9,8,7,6,5,4,3,2,1});

    // Capture index and value
    for(const auto& [i, n] : enumerate(myVec)){
        std::cout << "index: " << i << " value: " << n << std::endl;
        
        // n is mutable
        ++n; // will increase all values in the list after printing
    }

    std::map<std::string, int> map{{"a", 10}, {"b", 9},{"c", 7}, {"d", 8}};
    
    // Capture just the index
    for(auto i : enumerate(map)) {
        // i is the index for key-value pair map[i]
        std::cout << "index: " << i << std::endl;
    }
}
```

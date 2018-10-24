# C-Python-like-Iterators
Header only and using modern C++ 17 and templates, provides a function `enumerate` that easily returns key-value pairs for any standard container type as seen in the Python programming language.

# Minimal Working Example
```
#include "Enumerate.h"
#include <iostream>
#include <vector>
#include <map>
#include <string>

int main(int argc, char** argv) {
    std::vector<int> myVec({10,9,8,7,6,5,4,3,2,1});

    // Capture index and value
    for(const auto& [i, n] : enumerate(myVec)){
        std::cout << "index: " << i << " value: " << n << std::endl;
        
        // n is mutable
        ++n; // will increase all values in the list after printing
    }

    std::map<std::string, int> map{{"a", 10}, {"b", 9},{"c", 7}, {"d", 8}};
    
    // Capture just the index
    for(int index : enumerate(map)) {
        // index for key-value pair as if it was sequential
        std::cout << "index: " << index << std::endl;
    }
    
    // Capture just the key
    for(std::string key : enumerate(map)) {
        // the resolved value type has to be the same as the map's key type
        std::cout << "key: " << key << std::endl;
    }
}
```

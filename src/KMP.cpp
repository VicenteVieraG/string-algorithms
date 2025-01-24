#include <string>
#include <vector>

#include <KMP.hpp>

const std::vector<unsigned int> LPSArray(const std::string& pattern){
    std::vector<unsigned int> LPS(pattern.size(), 0);
    unsigned int length = 0; // Longest Prefix-Suffix size
    unsigned int i = 1; // Pattern index. Index 0 has no self suffix or prefix.

    while(i < pattern.size()){
        if(pattern[length] == pattern[i]) LPS[i] = ++length;
        else if(length = LPS[length ? length - 1 : 0]; length > 0) continue;
        
        i++;
    }

    return LPS;
}
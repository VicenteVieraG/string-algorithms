#include <iostream>
#include <cstddef>
#include <string>
#include <vector>
#include <utility>

#include <KMP.hpp>

std::vector<unsigned int> LPSArray(const std::string& pattern){
    const std::size_t patternSize = pattern.size();
    std::vector<unsigned int> LPS(patternSize, 0);
    unsigned int length = 0; // Longest Prefix-Suffix size
    unsigned int i = 1; // Pattern index. Index 0 has no self suffix nor prefix.

    while(i < patternSize){
        if(pattern[i] == pattern[length]) LPS[i] = ++length;
        else if(length = LPS[length ? length - 1 : 0]; length > 0) continue;

        i++;
    }

    return LPS;
}

std::vector<unsigned int> KMP(const std::string& pattern, const std::string& text){
    if(pattern.empty() || text.empty() || pattern.size() > text.size())
        return std::vector<unsigned int>(0);

    const std::vector<unsigned int> LPS = LPSArray(pattern);
    const std::size_t patternSize = pattern.size();
    const std::size_t textSize = text.size();
    std::vector<unsigned int> occurrences;
    unsigned int i = 0;
    unsigned int j = 0;

    while(i < textSize){
        if(text[i] == pattern[j]){
            if(j == patternSize - 1){ // Pattern found
                occurrences.push_back(i - j);
                j = LPS[j];
            }else j++;
            i++;
        }else j > 0 ? j = LPS[j - 1] : i++;
    }

    return occurrences;
}

void testKMP(){
    // Format: <text, pattern>
    const std::pair<std::string, std::string> testCases[] = {
        {"zzzabczzz", "abc"},
        {"ababa", "aba"},
        {"aaaaa", "aaa"},
        {"dogdogdog", "cat"},
        {"abc", "abc"},
        {"abcabcabc", "abc"},
        {"hola", ""},
        {"", "hola"},
        {"corto", "largote"},
        {"testtesttest", "test"}
    };

    for(const auto& [text, pattern] : testCases){
        std::cout<<"Text: "<<text<<std::endl;
        std::cout<<"Pattern: "<<pattern<<std::endl;
        std::cout<<"Ocurrences:"<<std::endl;
        
        const std::vector<unsigned int> ocurrences = KMP(pattern, text);

        std::cout<<"[ ";
        for(const auto& ocurrence : ocurrences) std::cout<<ocurrence<<" ";
        std::cout<<"]\n"<<std::endl;
    }
}
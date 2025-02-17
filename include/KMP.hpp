#ifndef KMP_HPP
#define KMP_HPP

#include <string>
#include <vector>

/** 
 * @brief Create the Longest Prefix wich is also a Suffix Array
 * @param pattern String to be searched
 * @return An std::vector<unsigned int> with the Longest Prefix wich is also a
 * Suffix.
 */
std::vector<unsigned int> LPSArray(const std::string& pattern);

/**
 * @brief Search for the pattern in the text using KMP algorithm.
 * @param pattern String to be searched.
 * @param text String to be searched in.
 * @return An std::vector<unsigned int> with the ocurrences' indexes in the text.
 */
std::vector<unsigned int> KMP(const std::string& pattern, const std::string& text);
void testKMP();

#endif
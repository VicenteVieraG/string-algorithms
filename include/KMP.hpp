#ifndef KMP_HPP
#define KMP_HPP

#include <string>
#include <vector>

/** 
 * @brief Create the Longest Prefix wich is also a Suffix Array
 * @param pattern String pattern to be searched
 * @return const std::vector<unsigned int>
 */
const std::vector<unsigned int> LPSArray(const std::string& pattern);

#endif
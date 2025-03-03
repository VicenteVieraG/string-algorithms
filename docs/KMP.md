KMP
====================================
> Knuth-Morris-Pratt algorithm  

## Description
The Knuth-Morris-Pratt algorithm is a *pattern matching algorithm*. Given a fixed pattern and a text, it will find all the occurrences in the text. What makes KMP better than brute-force is that it can *remember* characters it has already matched and avoid making unecessary extra comparisons.

## Implementation
The KMP algorithm has two main steps:
- Create LPS array.
- Search the pattern in the text using the LPS array.

### LPS
The LPS array is an auxiliary data structure used by KMP to optimize the pattern search in the text.

Given a pattern *P* of size *m*, the LPS algorithm will return an array *LPS* of size *m* where, for each subindex *i* of *P*, will count the longest prefix wich is also a suffix at `P[i]` and write it down in `LPS[i]`.

#### Build the LPS array
1. Define an LPS array of size m initialized to 0.
2. Declare two variables:
    - `length`: Initialized as 0. This is the length of the longest prefix wich is also a sufix.
    - `i`: Initialized as 1. This is the pattern's subindex. By default, pattern at subindex 0 has no self prefix nor suffix.
The process is as follows:
- if `P[i] == P[length]`, then `LPS[i] = length + 1` and advance in both, `i` and `length`.
- if `P[i] != P[length]`
  - if `length > 0`, we take a step-back `length = LPS[length - 1]` and repeat the comparison with the new length value.
  - if `length == 0`, we simply assign `LPS[i] = 0` and advance in `i`.

This can be verbalized as follows: if we can not extend the LPS at the current subindex of *P*, then search one step back in the LPS array to try with a smaller LPS at the previous LPS array position. If it is 0, then our current LPS can not be extended, so its size is 0 and we move on to the next position of *P*.

#### Example step by step
`P = "ABABCABAB"`

| i   | P[i] | LPS | Explanation                                                 |
| --- | ---- | --- | ----------------------------------------------------------- |
| 0   | A    | 0   | First character is always 0                                 |
| 1   | B    | 0   | No prefix/suffix                                            |
| 2   | A    | 1   | "A" is a prefix and a suffix                                |
| 3   | B    | 2   | "AB" is a prefix and a suffix                               |
| 4   | C    | 0   | There is no match so we can't extend the LPS. Set `len = 0` |
| 5   | A    | 1   | "A" is a prefix/suffix                                      |
| 6   | B    | 2   | "AB" is a prefix/suffix                                     |
| 7   | A    | 3   | "ABA" is a prefix/suffix                                    |
| 8   | B    | 4   | "ABAB is a prefix/suffix                                    |

The final LPS array is:  
`LPS = [0, 0, 1, 2, 0, 1, 2, 3, 4]`

### KMP implementation
Once we have built the LPS array, we can start searching the pattern in the text in an efficient way. The general idea of the algorithm is:
- Compare the pattern's and text's characters in search of matches.
- If there is a match, advance in both, the text and the pattern.
- If there is a mismatch, instead backtracking in the text, the LPS array helps determine the longest proper prefix that is also a suffix, allowing us to resume the search efficiently.

The LPS array tells us how much of the pattern we have already matched with itself. This allows us to avoid redundant comparisons by shifting the pattern intelligently instead of starting over

#### KMP search function
I added an edge-case guard *if* clause at the beginning of the KMP function to handle some exceptions I could think of, like:
- The pattern is empty.
- The text is empty.
- The pattern is longer than the text.

After the initial validations, the algorithm can now start to make the necessary inicializations.
##### Variable initialization
- `LPS[]`: The LPS array initialized with the LPSArray function taking the pattern as a parameter.
- `patternSize`: A constant with the pattern's size.
- `textSize`: A constant with the text's size.
- `occurrences`: A vector default initialized. It will store the starting positions of each occurrence of the pattern in the text.
- `i`: initialized to 0. It is the text's subindex iterator.
- `j`: initialized to 0. It is the pattern's subindex iterator.
##### Pattern search
To implement the actual search, we need to iterate through the text.
1. if `text[i] == pattern[j]`
   - if `j == patternSize - 1`, it means an occurrence has been found in the text
     - Compute the starting position of the occurrence with a simple substraction (`i - j`) and add it to `occurrences`.
     - Update `j`'s value to [`LPS[j]`](#kmp-variations).
   - Else, advance in both subindexes. `i` always advances whenever a match is found (`text[i] == pattern[j]`).
2. if `text[i] != pattern[j]`
   - if `j > 0`, update `j` to `LPS[j - 1]`. This means that instead of restarting the comparison from the beginning of the pattern, we jump to the longest prefix that is also a suffix, leveraging previous matches. Else, advance in `i`. This means that there are no characters left from the pattern that can be used to avoid extra comparisons, so we carry on comparing the pattern from the beginning.
3. Finally, return `occurrences`.

##### KMP variations
There are different approaches to the KMP algorithm. In my first attemp, I made the *"standard"* (just to give it a name) implementation. The only difference between the standard implementation and the one I ended using is a single line of code:
```Cpp
if(text[i] == pattern[j]){
  if(j == patternSize - 1){
      occurrences.push_back(i - j);
      j = LPS[j];  // <--- This exact line! It changes to: j = LPS[j - 1];
  }else j++;
}else j > 0 ? j = LPS[j - 1] : i++;
```

When an occurrence is found, the *standard* method uses `j = LPS[j - 1]` to update `j`'s subindex value instead of `j = LPS[j]`. What happens in the standard way is that, when a match is found, it looks one position back in the LPS array so that, for the next iteration of `i`, we do not take into consideration all of the characters from the previous ocurrence. This is good for searches in documents and writings because we only care about finding the exact word in the document, but it can not find all the substrings of the pattern in the text. Let me explain it with a example I made to test my algorithm: Let `pattern = "aba"` and `text = "ababa"`. The standard algorithm would only recognize the pattern at the beginning of the text and ingnore the appearence of the pattern in the rest of the word: "__aba__ ba", is missing "ab __aba__".

The standard version assigns `j` a previous value of the LPS array to compare it with the current `i` text's subindex, therefore, stteping right into the next character after the occurrence. The version I implemented does not step back, so we can compare the current LPS at the next iteration.
#include <iostream>
#include <vector>
#include <algorithm>

std::string mergeStrings(const std::vector<std::string>& words) {
    std::string s;
    
    for (const auto& word : words) {
        for (size_t i = 0; i < word.length(); ++i) {
            std::string currentSubstring = word.substr(i);
            if (s.find(currentSubstring) == std::string::npos) {
                s += currentSubstring;
            }
        }
    }
    
    std::sort(s.begin(), s.end());
    
    return s;
}

int main() {
    int N;
    
    while (std::cin >> N && N != 0) {
        std::vector<std::string> words(N);
        
        for (int i = 0; i < N; ++i) {
            std::cin >> words[i];
        }
        
        std::string result = mergeStrings(words);
        
        std::cout << result << std::endl;
    }
    
    return 0;
}
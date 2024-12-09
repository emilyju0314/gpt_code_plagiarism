#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>

// Function to count the number of integers in the multiset that match the given pattern
int countMatchingIntegers(std::unordered_map<long long, int>& multiset, std::string pattern) {
    int count = 0;
    for (auto& pair : multiset) {
        std::string numStr = std::to_string(pair.first);
        if (numStr.length() < pattern.length()) {
            numStr = std::string(pattern.length() - numStr.length(), '0') + numStr;
        } else if (numStr.length() > pattern.length()) {
            pattern = std::string(numStr.length() - pattern.length(), '0') + pattern;
        }
        
        bool match = true;
        for (int i = 0; i < numStr.length(); i++) {
            if (pattern[i] == '0' && (numStr[i] - '0') % 2 == 1) {
                match = false;
                break;
            } else if (pattern[i] == '1' && (numStr[i] - '0') % 2 == 0) {
                match = false;
                break;
            }
        }
        
        if (match) {
            count += pair.second;
        }
    }
    
    return count;
}

int main() {
    int t;
    std::cin >> t;
    
    std::unordered_map<long long, int> multiset;
    
    for (int i = 0; i < t; i++) {
        char c;
        std::cin >> c;
        
        if (c == '+') {
            long long ai;
            std::cin >> ai;
            multiset[ai]++;
        } else if (c == '-') {
            long long ai;
            std::cin >> ai;
            multiset[ai]--;
            if (multiset[ai] == 0) {
                multiset.erase(ai);
            }
        } else if (c == '?') {
            std::string pattern;
            std::cin >> pattern;
            std::cout << countMatchingIntegers(multiset, pattern) << std::endl;
        }
    }
    
    return 0;
}
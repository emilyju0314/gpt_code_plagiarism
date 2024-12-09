#include <iostream>
#include <vector>
#include <algorithm>

int main() {
    std::string s;
    std::cin >> s;
    
    int k;
    std::cin >> k;
    
    std::vector<std::string> substrings;
    for (int i = 0; i < s.length(); i++) {
        for (int j = 1; j <= s.length() - i; j++) {
            substrings.push_back(s.substr(i, j));
        }
    }
    
    std::sort(substrings.begin(), substrings.end());
    
    if (k > substrings.size()) {
        std::cout << "No such line." << std::endl;
    } else {
        std::cout << substrings[k-1] << std::endl;
    }
    
    return 0;
}
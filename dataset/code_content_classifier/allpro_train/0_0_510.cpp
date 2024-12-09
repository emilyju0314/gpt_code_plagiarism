

#include <iostream>
#include <unordered_set>

int main() {
    std::string s1, s2;
    std::cin >> s1 >> s2;
    
    std::unordered_set<char> set1(s1.begin(), s1.end());
    
    bool found = false;
    for(char c : s2) {
        if(set1.find(c) != set1.end()) {
            found = true;
            break;
        }
    }
    
    if(found) {
        std::cout << "Yes" << std::endl;
    } else {
        std::cout << "No" << std::endl;
    }
    
    return 0;
}
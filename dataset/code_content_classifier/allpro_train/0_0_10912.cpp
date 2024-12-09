#include <iostream>
#include <unordered_set>
#include <string>

int main() {
    int n;
    std::cin >> n;
    
    std::unordered_set<std::string> dictionary;
    
    for (int i = 0; i < n; ++i) {
        std::string instruction, str;
        std::cin >> instruction >> str;
        
        if (instruction == "insert") {
            dictionary.insert(str);
        } else if (instruction == "find") {
            if (dictionary.find(str) != dictionary.end()) {
                std::cout << "yes" << std::endl;
            } else {
                std::cout << "no" << std::endl;
            }
        }
    }
    
    return 0;
}
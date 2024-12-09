#include <iostream>
#include <vector>
#include <algorithm>

int main() {
    int n;
    std::cin >> n;
    
    std::vector<std::string> words(n);
    for (int i = 0; i < n; i++) {
        std::cin >> words[i];
        std::sort(words[i].begin(), words[i].end());
    }
    
    for (int i = 0; i < n; i++) {
        std::cout << words[i] << std::endl;
    }
    
    return 0;
}
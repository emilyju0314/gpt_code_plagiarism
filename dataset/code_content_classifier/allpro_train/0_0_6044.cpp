#include <iostream>
#include <algorithm>

int main() {
    int n;
    std::cin >> n;
    
    for (int i = 0; i < n; i++) {
        std::string s;
        std::cin >> s;
        
        std::sort(s.begin(), s.end());
        std::string largest = s;
        std::string smallest = s;
        
        std::sort(largest.rbegin(), largest.rend());
        std::sort(smallest.begin(), smallest.end());
        
        int diff = std::stoi(largest) - std::stoi(smallest);
        std::cout << diff << std::endl;
    }
    
    return 0;
}
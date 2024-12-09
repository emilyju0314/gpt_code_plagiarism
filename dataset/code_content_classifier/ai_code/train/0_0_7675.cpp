#include <iostream>
#include <unordered_set>

int main() {
    int n;
    std::cin >> n;
    
    std::unordered_set<std::string> names;
    
    for (int i = 0; i < n; i++) {
        std::string name;
        std::cin >> name;
        
        if (names.count(name) > 0) {
            std::cout << "YES" << std::endl;
        } else {
            names.insert(name);
            std::cout << "NO" << std::endl;
        }
    }
    
    return 0;
}
#include <iostream>

int main() {
    int a, m;
    std::cin >> a >> m;
    
    int current = a;
    
    while (current % m != 0) {
        current += current % m;
    }
    
    if (current % m == 0) {
        std::cout << "Yes" << std::endl;
    } else {
        std::cout << "No" << std::endl;
    }
    
    return 0;
}
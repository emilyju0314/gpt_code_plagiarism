#include <iostream>

int main() {
    int n, total = 0;
    std::cin >> n;
    
    for (int i = 0; i < n; i++) {
        int amount;
        std::cin >> amount;
        total += amount;
    }
    
    int average = total / n;
    std::cout << average << std::endl;
    
    return 0;
}
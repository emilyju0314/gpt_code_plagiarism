#include <iostream>

int main() {
    int n, k;
    std::cin >> n >> k;

    char current = 'a';
    
    for (int i = 0; i < n; i++) {
        std::cout << current;
        
        // Move to the next distinct symbol
        current++;
        if (current - 'a' == k) {
            current = 'a';
        }
    }

    return 0;
}
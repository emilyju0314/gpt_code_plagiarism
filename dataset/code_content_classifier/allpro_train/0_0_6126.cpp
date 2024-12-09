#include <iostream>

int main() {
    int N;
    std::cin >> N;
    
    int total = 0;
    for (int i = 0; i < N; i++) {
        int l, r;
        std::cin >> l >> r;
        total += r - l + 1;
    }
    
    std::cout << total << std::endl;
    
    return 0;
} 

// Sample Input
// 1
// 24 30

// Sample Output
// 7

// Sample Input
// 2
// 6 8
// 3 3

// Sample Output
// 4
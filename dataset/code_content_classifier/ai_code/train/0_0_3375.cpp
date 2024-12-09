#include <iostream>

int main() {
    int N;
    std::cin >> N;
    
    int min = 1e9 + 1; // Initialize min to a very large value
    int minIndex = 0;
    
    for (int i = 1; i <= N; i++) {
        int num;
        std::cin >> num;
        
        if (num < min) {
            min = num;
            minIndex = i;
        }
    }
    
    std::cout << minIndex << std::endl;
    
    return 0;
}
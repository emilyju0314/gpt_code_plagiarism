#include <iostream>

int main() {
    int N;
    
    while (true) {
        std::cin >> N;
        
        if (N == 0) {
            break;
        }
        
        long long tiles = ((long long)N * N * 3) + 2;
        std::cout << tiles << std::endl;
    }
    
    return 0;
}
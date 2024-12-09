#include <iostream>

int main() {
    int N, K;
    std::cin >> N >> K;
    
    if (N % 2 == 1) {
        std::cout << -1 << std::endl;
    } else {
        for (int i = 0; i < N; i++) {
            int a = K + 2*i + 1;
            int b = K + 2*i + 2;
            int c = K + 2*N + i;
            std::cout << a << " " << b << " " << c << std::endl;
        }
    }
    
    return 0;
}
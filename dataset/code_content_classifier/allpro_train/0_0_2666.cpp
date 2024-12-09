#include <iostream>

int main() {
    int A, B, K;
    std::cin >> A >> B >> K;

    for(int i = A; i <= B; i++) {
        if(i <= A+K-1 || i >= B-K+1) {
            std::cout << i << std::endl;
        }
    }

    return 0;
}
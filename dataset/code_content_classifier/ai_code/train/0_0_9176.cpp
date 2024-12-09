#include <iostream>

int main() {
    int N;
    std::cin >> N;

    int xor_sum = 0;
    for(int i = 0; i < N; i++) {
        int a;
        std::cin >> a;
        xor_sum ^= a;
    }

    if(xor_sum == 0 || N % 2 == 0) {
        std::cout << "Bob";
    } else {
        std::cout << "Alice";
    }

    return 0;
}
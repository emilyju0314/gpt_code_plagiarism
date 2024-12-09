#include <iostream>

int main() {
    int N;
    std::cin >> N;

    int highestPowerOfTwo = 1;
    while (highestPowerOfTwo * 2 <= N) {
        highestPowerOfTwo *= 2;
    }

    std::cout << highestPowerOfTwo << std::endl;
    
    return 0;
}
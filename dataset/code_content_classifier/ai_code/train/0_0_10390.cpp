#include <iostream>
#include <sstream>
#include <cmath>

int calculateLength(int N) {
    if (N == 0) return 1; // Special case for 0
    int length = 0;
    int temp = N;
    while (temp > 0) {
        temp /= 10; // Divide by 10 to count number of digits
        length++;
    }
    return length;
}

int main() {
    int N;
    while (true) {
        std::cin >> N;
        if (N == -1) break;
        
        int length = calculateLength(N);
        std::cout << length << std::endl;
    }
    return 0;
}
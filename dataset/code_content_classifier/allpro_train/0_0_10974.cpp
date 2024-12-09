#include <iostream>
#include <cmath>

int main() {
    long long N;
    std::cin >> N;

    long long i = 1, j = 1;
    long long moves = 0;

    while (i * j < N) {
        if (i < j) {
            i++;
        } else {
            j++;
        }
        moves++;
    }

    std::cout << moves << std::endl;

    return 0;
}
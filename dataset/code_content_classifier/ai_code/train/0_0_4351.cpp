#include <iostream>
#include <string>

int sumOfDigits(long long n) {
    int sum = 0;
    while (n > 0) {
        sum += n % 10;
        n /= 10;
    }
    return sum;
}

int minMoves(long long n, int s) {
    int moves = 0;
    while (sumOfDigits(n) > s) {
        int rem = 10 - n % 10;
        n += rem;
        moves += rem;
        while (n % 10 == 0) {
            n /= 10;
        }
    }
    return moves;
}

int main() {
    int t;
    std::cin >> t;

    for (int i = 0; i < t; i++) {
        long long n;
        int s;
        std::cin >> n >> s;
        std::cout << minMoves(n, s) << std::endl;
    }

    return 0;
}
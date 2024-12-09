#include <iostream>
#include <cmath>

int main() {
    int t;
    std::cin >> t;

    while(t--) {
        int n;
        std::cin >> n;

        int twos = 0;
        while(n % 2 == 0) {
            n /= 2;
            twos++;
        }

        int threes = 0;
        while(n % 3 == 0) {
            n /= 3;
            threes++;
        }

        if(n != 1) {
            std::cout << "-1" << std::endl;
        } else if(twos > threes) {
            std::cout << "-1" << std::endl;
        } else {
            int moves = threes - twos + threes;
            std::cout << moves << std::endl;
        }
    }

    return 0;
}
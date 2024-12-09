#include <iostream>

int main() {
    int T, S, q;
    std::cin >> T >> S >> q;

    int timesRestarted = 0;
    while (S < T) {
        S *= q;
        timesRestarted++;
    }

    std::cout << timesRestarted << std::endl;

    return 0;
}
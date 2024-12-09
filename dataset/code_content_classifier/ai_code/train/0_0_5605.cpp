#include <iostream>

int main() {
    int N, X, T;
    std::cin >> N >> X >> T;

    int time_needed = ((N + X - 1) / X) * T; // Round up division to get the minimum number of minutes needed
    std::cout << time_needed << std::endl;

    return 0;
}
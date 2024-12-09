#include <iostream>
#include <cmath>

int main() {
    int N, M;
    std::cin >> N >> M;

    int games = N - M - 1;
    std::cout << games << std::endl;

    return 0;
}
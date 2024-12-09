#include <iostream>

int main() {
    int N, K;
    std::cin >> N >> K;

    int min_diff = N % K;
    std::cout << min_diff << std::endl;

    return 0;
}
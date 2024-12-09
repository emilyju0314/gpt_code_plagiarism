#include <iostream>

int main() {
    int N, i;
    std::cin >> N >> i;

    // The j-th car from the back is N - i + 1
    int j = N - i + 1;

    std::cout << j << std::endl;

    return 0;
}
#include <iostream>
#include <vector>

int main() {
    std::vector<int> sequence = {1, 1, 1, 2, 1, 2, 1, 5, 2, 2, 1, 5, 1, 2, 1, 14, 1, 5, 1, 5, 2, 2, 1, 15, 2, 2, 5, 4, 1, 4, 1, 51};

    int K;
    std::cin >> K;

    // Output the K-th element of the sequence
    std::cout << sequence[K - 1] << std::endl;

    return 0;
}
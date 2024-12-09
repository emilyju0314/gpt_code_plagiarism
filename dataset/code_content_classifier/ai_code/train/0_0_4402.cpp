#include <iostream>

int main() {
    int N;
    std::cin >> N;

    int totalCandies = 0;
    for (int i = 1; i <= N; i++) {
        totalCandies += i;
    }

    std::cout << totalCandies << std::endl;

    return 0;
}
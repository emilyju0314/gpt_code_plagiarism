#include <iostream>
#include <vector>
#include <algorithm>

int main() {
    int n;
    std::cin >> n;

    std::vector<int> numbers(n);
    for (int i = 0; i < n; i++) {
        std::cin >> numbers[i];
    }

    std::sort(numbers.begin(), numbers.end());

    if (n % 2 == 1) {
        std::cout << numbers[n/2] << std::endl;
    } else {
        std::cout << numbers[(n/2) - 1] << std::endl;
    }

    return 0;
}
#include <iostream>
#include <vector>
#include <algorithm>

int main() {
    int n;
    std::cin >> n;

    std::vector<int> citizens(n);
    int max_welfare = 0;

    for (int i = 0; i < n; i++) {
        std::cin >> citizens[i];
        max_welfare = std::max(max_welfare, citizens[i]);
    }

    int total = 0;
    for (int i = 0; i < n; i++) {
        total += max_welfare - citizens[i];
    }

    std::cout << total << std::endl;

    return 0;
}
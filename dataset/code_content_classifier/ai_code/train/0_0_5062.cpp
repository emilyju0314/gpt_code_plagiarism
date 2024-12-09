#include <iostream>
#include <vector>

int main() {
    int n, k;
    std::cin >> n >> k;

    std::vector<int> population(n);
    for (int i = 0; i < n; i++) {
        std::cin >> population[i];
    }

    int odd_count = 0;
    int even_count = 0;

    for (int i = 0; i < n; i++) {
        if (population[i] % 2 == 0) {
            even_count++;
        } else {
            odd_count++;
        }
    }

    int remaining_cities = n - k;

    if (remaining_cities <= odd_count) {
        if (remaining_cities % 2 == 0) {
            std::cout << "Daenerys" << std::endl;
        } else {
            std::cout << "Stannis" << std::endl;
        }
    } else {
        if (odd_count % 2 == 0) {
            std::cout << "Daenerys" << std::endl;
        } else {
            std::cout << "Stannis" << std::endl;
        }
    }

    return 0;
}
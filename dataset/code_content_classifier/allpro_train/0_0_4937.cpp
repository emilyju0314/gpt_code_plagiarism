#include <iostream>
#include <vector>

int main() {
    int n;
    std::cin >> n;

    std::vector<long long> cows(n);
    for (int i = 0; i < n; i++) {
        std::cin >> cows[i];
    }

    int p;
    std::cin >> p;

    for (int i = 0; i < p; i++) {
        int a, b;
        std::cin >> a >> b;

        long long total_mass = 0;
        for (int j = a-1; j < n; j += b) {
            total_mass += cows[j];
        }

        std::cout << total_mass << std::endl;
    }

    return 0;
}
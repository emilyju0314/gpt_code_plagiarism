#include <iostream>
#include <vector>

int main() {
    int n;
    std::cin >> n;

    std::vector<int> a(n);
    for (int i = 0; i < n; i++) {
        std::cin >> a[i];
    }

    std::vector<std::vector<int>> w(n, std::vector<int>(n));
    for (int i = 0; i < n; i++) {
        for (int k = 0; k < n - i; k++) {
            std::cin >> w[i][k];
        }
    }

    std::vector<std::vector<int>> mass(n, std::vector<int>(n, 0));
    mass[0][0] = a[0];

    for (int i = 0; i < n - 1; i++) {
        for (int k = 0; k < n - i; k++) {
            if (mass[i][k] > w[i][k]) {
                int excess = mass[i][k] - w[i][k];
                mass[i + 1][k] += excess / 2;
                mass[i + 1][k + 1] += excess / 2;
            }
        }
    }

    if (mass[n - 1][0] > w[n - 1][0]) {
        std::cout << "Cerealguy" << std::endl;
    } else {
        std::cout << "Fat Rat" << std::endl;
    }

    return 0;
}
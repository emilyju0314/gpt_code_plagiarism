#include <iostream>
#include <vector>

int main() {
    int n;
    std::cin >> n;

    std::vector<std::vector<int>> table(n, std::vector<int>(n));
    std::vector<int> a(n);

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            std::cin >> table[i][j];
        }
    }

    for (int i = 0; i < n; i++) {
        a[i] = (table[i][0] * table[i][1]) / table[0][1];
    }

    for (int i = 0; i < n; i++) {
        std::cout << a[i] << " ";
    }

    return 0;
}
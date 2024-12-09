#include <iostream>
#include <vector>

int main() {
    int n;
    std::cin >> n;

    std::vector<int> cubes(n);
    for (int i = 0; i < n; i++) {
        std::cin >> cubes[i];
    }

    std::vector<int> result(n);
    for (int i = 0; i < n; i++) {
        if (i % 2 == 0) {
            result[i / 2] = cubes[i];
        } else {
            result[n - 1 - i / 2] = cubes[i];
        }
    }

    for (int i = 0; i < n; i++) {
        std::cout << result[i] << " ";
    }

    return 0;
}
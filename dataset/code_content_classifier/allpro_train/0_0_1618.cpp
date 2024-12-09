#include <iostream>
#include <vector>

int main() {
    int n;
    std::cin >> n;

    std::vector<int> permutation(n);
    for (int i = 0; i < n; i++) {
        std::cin >> permutation[i];
    }

    int m;
    std::cin >> m;

    int inversions = 0;

    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            if (permutation[i] > permutation[j]) {
                inversions++;
            }
        }
    }

    bool isOdd = inversions % 2 != 0;

    for (int k = 0; k < m; k++) {
        int l, r;
        std::cin >> l >> r;

        int length = r - l + 1;
        inversions += length * (length - 1) / 2;

        isOdd = inversions % 2 != 0;

        if (isOdd) {
            std::cout << "odd\n";
        } else {
            std::cout << "even\n";
        }
    }

    return 0;
}
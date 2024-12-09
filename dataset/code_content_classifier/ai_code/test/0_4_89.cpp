#include <iostream>
#include <vector>

bool canEraseSequence(int n, std::vector<int>& sequence) {
    int count = 0;
    for (int i = 0; i < n; i++) {
        if (sequence[i] % 2 == 0) {
            count++;
        }
    }
    return count == n;
}

int main() {
    int t;
    std::cin >> t;

    for (int i = 0; i < t; i++) {
        int n;
        std::cin >> n;

        std::vector<int> sequence(n);
        for (int j = 0; j < n; j++) {
            std::cin >> sequence[j];
        }

        if (canEraseSequence(n, sequence)) {
            std::cout << "NO" << std::endl;
        } else {
            std::cout << "YES" << std::endl;
        }
    }

    return 0;
}
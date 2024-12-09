#include <iostream>
#include <vector>

int countDifferentBits(int a, int b) {
    int count = 0;
    while (a > 0 || b > 0) {
        if ((a & 1) != (b & 1)) {
            count++;
        }
        a >>= 1;
        b >>= 1;
    }
    return count;
}

int main() {
    int n, m, k;
    std::cin >> n >> m >> k;

    std::vector<int> armies(m+1);
    for (int i = 0; i <= m; i++) {
        std::cin >> armies[i];
    }

    int friends = 0;
    for (int i = 0; i < m; i++) {
        if (countDifferentBits(armies[i], armies[m]) <= k) {
            friends++;
        }
    }

    std::cout << friends << std::endl;

    return 0;
}
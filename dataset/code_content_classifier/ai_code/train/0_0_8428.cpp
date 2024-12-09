#include <iostream>
#include <vector>

std::vector<int> findPermutation(int n, int l, int r, int s) {
    std::vector<int> permutation(n, 0);

    int sum = (r - l + 1) * (r + l) / 2;

    int extraSum = s - sum;

    if (extraSum < 0 || extraSum > n - r + l - 1) {
        permutation[0] = -1;
        return permutation;
    }

    int curr = 1;
    for (int i = 0; i < n; i++) {
        if (i >= l - 1 && i <= r - 1) {
            permutation[i] = curr + extraSum;
        } else {
            permutation[i] = curr;
            curr++;
        }
    }

    return permutation;
}

int main() {
    int t;
    std::cin >> t;

    while (t--) {
        int n, l, r, s;
        std::cin >> n >> l >> r >> s;

        std::vector<int> result = findPermutation(n, l, r, s);

        for (int i = 0; i < n; i++) {
            if (i == n - 1) {
                std::cout << result[i] << std::endl;
            } else {
                std::cout << result[i] << " ";
            }
        }

    }

    return 0;
}
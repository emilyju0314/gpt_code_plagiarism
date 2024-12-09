#include <iostream>
#include <vector>

int countPairs(std::vector<int>& a, int n, int k) {
    int count = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (i != j) {
                long long concat = (long long)a[i] * 10;
                concat += a[j];
                if (concat % k == 0) {
                    count++;
                }
            }
        }
    }
    return count;
}

int main() {
    int n, k;
    std::cin >> n >> k;

    std::vector<int> a(n);
    for (int i = 0; i < n; i++) {
        std::cin >> a[i];
    }

    std::cout << countPairs(a, n, k) << std::endl;

    return 0;
}
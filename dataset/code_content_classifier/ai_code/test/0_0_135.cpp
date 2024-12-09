#include <iostream>
#include <vector>
#include <algorithm>

int main() {
    int t;
    std::cin >> t;

    while (t--) {
        int n, k;
        std::cin >> n >> k;

        std::vector<int> a(n);
        for (int i = 0; i < n; i++) {
            std::cin >> a[i];
        }

        std::sort(a.begin(), a.end());

        int score = 0;
        int i = 0, j = n - 1;
        while (k--) {
            score += a[i] / a[j];
            i++;
            j--;
        }

        int remaining = 0;
        for (int x = i; x < n; x++) {
            remaining += a[x];
        }

        score += remaining;

        std::cout << score << std::endl;
    }

    return 0;
}
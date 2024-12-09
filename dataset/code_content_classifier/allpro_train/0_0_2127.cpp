#include <iostream>
#include <vector>
#include <algorithm>

int main() {
    int n, k;
    std::cin >> n >> k;

    std::vector<int> wealth(n);
    for (int i = 0; i < n; i++) {
        std::cin >> wealth[i];
    }

    std::sort(wealth.begin(), wealth.end());

    long long min_diff = wealth[n-1] - wealth[0];

    for (int i = 1; i <= k; i++) {
        if (wealth[0] == wealth[n-1]) {
            break;
        }
        long long richest = wealth[n-1];
        long long poorest = wealth[0];
        wealth[n-1]--;
        wealth[0]++;
        std::sort(wealth.begin(), wealth.end());
        min_diff = std::min(min_diff, wealth[n-1] - wealth[0]);
    }

    std::cout << min_diff << std::endl;

    return 0;
}
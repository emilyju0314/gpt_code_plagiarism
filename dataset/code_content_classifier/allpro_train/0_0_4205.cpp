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

    long long richest = wealth.back();
    long long poorest = wealth.front();

    for (int i = 0; i < k; i++) {
        if (wealth[0] == wealth.back()) {
            break;
        }
        richest--;
        poorest++;
        std::sort(wealth.begin(), wealth.end());
    }

    std::cout << richest - poorest << std::endl;

    return 0;
}
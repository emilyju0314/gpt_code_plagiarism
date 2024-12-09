#include <iostream>
#include <vector>
#include <algorithm>

int main() {
    int n, k;
    std::cin >> n >> k;

    std::vector<int> speeds(n);
    for(int i = 0; i < n; i++) {
        std::cin >> speeds[i];
    }

    std::sort(speeds.begin(), speeds.end(), std::greater<int>());

    std::cout << speeds[k - 1] << std::endl;

    return 0;
}
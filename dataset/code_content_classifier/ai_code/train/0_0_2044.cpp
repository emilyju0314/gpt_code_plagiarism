#include <iostream>
#include <vector>
#include <algorithm>

int main() {
    int n;
    std::cin >> n;

    std::vector<int> years(n);
    for (int i = 0; i < n; i++) {
        std::cin >> years[i];
    }

    std::sort(years.begin(), years.end());

    if (n % 2 == 0) {
        std::cout << years[n/2 - 1] << std::endl;
    } else {
        std::cout << years[n/2] << std::endl;
    }

    return 0;
}
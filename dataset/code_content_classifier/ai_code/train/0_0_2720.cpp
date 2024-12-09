#include <iostream>
#include <vector>
#include <algorithm>

int main() {
    int n;
    std::cin >> n;

    std::vector<int> columns(n);

    for (int i = 0; i < n; i++) {
        std::cin >> columns[i];
    }

    std::sort(columns.begin(), columns.end());

    for (int i = 0; i < n; i++) {
        std::cout << columns[i] << " ";
    }

    return 0;
}
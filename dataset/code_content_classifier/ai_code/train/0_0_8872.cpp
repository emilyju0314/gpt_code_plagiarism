#include <iostream>
#include <vector>
#include <algorithm>

int main() {
    int n;
    std::cin >> n;

    std::vector<int> ratings(n);
    for (int i = 0; i < n; ++i) {
        std::cin >> ratings[i];
    }

    std::vector<int> positions(n);
    for (int i = 0; i < n; ++i) {
        int cnt = 0;
        for (int j = 0; j < n; ++j) {
            if (ratings[j] > ratings[i] || (ratings[j] == ratings[i] && j < i)) {
                cnt++;
            }
        }
        positions[i] = cnt + 1;
    }

    for (int i = 0; i < n; ++i) {
        std::cout << positions[i] << " ";
    }

    return 0;
}
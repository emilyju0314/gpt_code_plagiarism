#include <iostream>
#include <vector>
#include <algorithm>

int main() {
    int n;
    std::cin >> n;

    std::vector<int> a(n);
    std::vector<int> b(n);

    for (int i = 0; i < n; i++) {
        std::cin >> a[i];
    }

    for (int i = 0; i < n; i++) {
        std::cin >> b[i];
    }

    int total_a = 0;
    int total_b = 0;
    for (int i = 0; i < n; i++) {
        total_a += a[i];
        total_b += b[i];
    }

    std::vector<int> remaining(n);
    for (int i = 0; i < n; i++) {
        remaining[i] = b[i] - a[i];
    }

    int max_remaining = *std::max_element(remaining.begin(), remaining.end());
    int second_max_remaining = total_b - max_remaining;

    if(total_a <= max_remaining || total_a <= second_max_remaining) {
        std::cout << "YES" << std::endl;
    } else {
        std::cout << "NO" << std::endl;
    }

    return 0;
}
#include <iostream>
#include <vector>
#include <algorithm>

int main() {
    int n;
    std::cin >> n;

    std::vector<int> distances(n);
    for (int i = 0; i < n; ++i) {
        std::cin >> distances[i];
    }

    int s, t;
    std::cin >> s >> t;

    if (s > t) {
        std::swap(s, t);
    }

    int total = 0;
    for (int i = s; i < t; ++i) {
        total += distances[i - 1];
    }

    int clockwise = total;
    int counterclockwise = 0;

    for (int i = 0; i < s - 1; ++i) {
        counterclockwise += distances[i];
    }
    for (int i = n-1; i >= t; --i) {
        counterclockwise += distances[i];
    }

    int result = std::min(clockwise, counterclockwise);

    std::cout << result << std::endl;

    return 0;
}
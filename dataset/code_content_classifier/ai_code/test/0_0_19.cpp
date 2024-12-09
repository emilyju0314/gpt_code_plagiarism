#include <iostream>
#include <vector>
#include <algorithm>

int minimal_coverage(std::vector<int> segments) {
    int n = segments.size();
    int end = 0;
    int length = segments[0];

    for (int i = 1; i < n; i++) {
        if (segments[i] < 0) {
            end = std::min(end, length + segments[i]);
        } else {
            end = std::max(end, length + segments[i]);
        }
        length += segments[i];
    }

    return length - end;
}

int main() {
    int t;
    std::cin >> t;

    while (t--) {
        int n;
        std::cin >> n;

        std::vector<int> segments(n);
        for (int i = 0; i < n; i++) {
            std::cin >> segments[i];
        }

        int result = minimal_coverage(segments);
        std::cout << result << std::endl;
    }

    return 0;
}
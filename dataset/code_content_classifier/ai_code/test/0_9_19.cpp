#include <iostream>
#include <vector>
#include <algorithm>

int main() {
    int t;
    std::cin >> t;

    for(int i = 0; i < t; i++) {
        int n;
        std::cin >> n;

        std::vector<int> segments(n);
        for(int j = 0; j < n; j++) {
            std::cin >> segments[j];
        }

        int current_end = 0;
        int max_coverage = segments[0];
        for(int j = 1; j < n; j++) {
            if(segments[j] < segments[j-1]) {
                current_end = std::max(current_end + segments[j], current_end - segments[j-1]);
            } else {
                current_end = std::max(current_end + segments[j], current_end + segments[j-1]);
            }
            max_coverage = std::max(max_coverage, current_end);
        }

        std::cout << max_coverage << std::endl;
    }

    return 0;
}
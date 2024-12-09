#include <iostream>

int main() {
    int t;
    std::cin >> t;

    while (t--) {
        int a, b, c;
        std::cin >> a >> b >> c;

        int totalDuration = a + 2*b + 3*c;

        // Try all possible combinations of assigning songs to each concert
        // and find the one that minimizes the absolute difference
        int minDiff = totalDuration;
        for (int i = 0; i <= a; ++i) {
            for (int j = 0; j <= b; ++j) {
                int concert1Duration = i + 2*j;
                int concert2Duration = totalDuration - concert1Duration;
                minDiff = std::min(minDiff, std::abs(concert1Duration - concert2Duration));
            }
        }

        std::cout << minDiff << std::endl;
    }

    return 0;
}
#include <iostream>
#include <algorithm>

int main() {
    int t;
    std::cin >> t;

    while (t--) {
        int a, b, c;
        std::cin >> a >> b >> c;

        // Sort the songs durations in increasing order
        int durations[3] = {a, b, c};
        std::sort(durations, durations + 3);

        // Calculate the sum of durations of all songs
        int total_duration = a + b + c;
        
        // Calculate the minimal possible difference between the concerts durations
        int min_diff = std::min(std::max(0, total_duration - durations[2] * 2), total_duration % 2);

        std::cout << min_diff << std::endl;
    }

    return 0;
}
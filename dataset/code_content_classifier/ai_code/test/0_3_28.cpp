#include <iostream>
#include <algorithm>
#include <cmath>

int main() {
    int t;
    std::cin >> t;

    while (t--) {
        int a, b, c;
        std::cin >> a >> b >> c;

        // Sort the songs
        int songs[] = {a, b, c};
        std::sort(songs, songs+3);

        // Calculate the sum of the durations of all songs
        int total = a + b + c;

        // Find the optimal distribution of songs to minimize the difference
        int first_concert_duration = songs[0] + songs[1];
        int second_concert_duration = songs[2];
        int diff = std::abs(first_concert_duration - second_concert_duration);

        // Output the minimal possible difference in minutes between the concerts durations
        std::cout << diff << std::endl;
    }

    return 0;
}
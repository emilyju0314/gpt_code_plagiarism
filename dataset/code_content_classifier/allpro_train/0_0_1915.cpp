#include <iostream>
#include <algorithm>

int main() {
    int a, b, c, d;
    std::cin >> a >> b >> c >> d;

    int min_duration = 0;

    // Sort the positions of ropewalkers
    int positions[3] = {a, b, c};
    std::sort(positions, positions + 3);

    // Calculate the distance between each pair of ropewalkers
    int diff1 = std::max(0, d - (positions[1] - positions[0]));
    int diff2 = std::max(0, d - (positions[2] - positions[1]));

    // Calculate the minimum duration of the performance
    min_duration = diff1 + diff2;

    std::cout << min_duration << std::endl;

    return 0;
}
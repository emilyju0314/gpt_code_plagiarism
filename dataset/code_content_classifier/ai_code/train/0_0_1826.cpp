#include <iostream>
#include <iomanip>

int main() {
    int h1, m1, h2, m2;
    char colon; // To read and skip the colon character in the input

    // Read input
    std::cin >> h1 >> colon >> m1;
    std::cin >> h2 >> colon >> m2;

    // Calculate the total minutes elapsed from midnight for both start and end time
    int totalMinutes1 = h1 * 60 + m1;
    int totalMinutes2 = h2 * 60 + m2;

    // Calculate the midpoint time in total minutes and then convert to hours and minutes
    int midpointTotalMinutes = (totalMinutes1 + totalMinutes2) / 2;
    int h3 = midpointTotalMinutes / 60;
    int m3 = midpointTotalMinutes % 60;

    // Output the midpoint time in the specified format
    std::cout << std::setfill('0') << std::setw(2) << h3 << ":" << std::setw(2) << m3 << std::endl;

    return 0;
}
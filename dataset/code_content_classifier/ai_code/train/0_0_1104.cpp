#include <iostream>
#include <algorithm>
#include <numeric>

int main() {
    int Y, W;
    std::cin >> Y >> W;

    int dotsPossibleOutcomes = 6 - std::max(Y, W) + 1; // Number of outcomes where Dot wins
    int totalOutcomes = 6; // Total number of possible outcomes

    // Find the greatest common divisor to reduce the fraction
    int gcd = std::gcd(dotsPossibleOutcomes, totalOutcomes);

    // Output the result in the required format
    if (dotsPossibleOutcomes == 0) {
        std::cout << "0/1" << std::endl;
    } else if (dotsPossibleOutcomes == totalOutcomes) {
        std::cout << "1/1" << std::endl;
    } else {
        std::cout << dotsPossibleOutcomes / gcd << "/" << totalOutcomes / gcd << std::endl;
    }

    return 0;
}
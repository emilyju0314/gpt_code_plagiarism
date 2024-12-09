#include <iostream>
#include <algorithm>

int main() {
    long long b, d, s;
    std::cin >> b >> d >> s;

    // Find the maximum number of meals Vasiliy had
    long long max_meals = std::max({b, d, s});

    // Calculate the minimum number of missed meals
    long long missed_meals = 0;
    if (max_meals == b) {
        missed_meals = std::max(0LL, b - d - 1) + std::max(0LL, b - s - 1);
    } else if (max_meals == d) {
        missed_meals = std::max(0LL, d - b - 1) + std::max(0LL, d - s - 1);
    } else {
        missed_meals = std::max(0LL, s - b - 1) + std::max(0LL, s - d - 1);
    }

    std::cout << missed_meals << std::endl;

    return 0;
}
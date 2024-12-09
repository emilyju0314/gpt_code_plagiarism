#include <iostream>
#include <algorithm>

int main() {
    int a, b, c, d, e, f;
    std::cin >> a >> b >> c >> d >> e >> f;

    int total_cost = 0;

    // Decide how many suits of each type can be formed
    int suits_first_type = std::min(a, d);
    int suits_second_type = std::min({b, c, d});

    // Calculate the total cost
    total_cost = suits_first_type * e + suits_second_type * f;

    std::cout << total_cost << std::endl;

    return 0;
}
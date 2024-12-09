#include <iostream>
#include <cmath>

int main() {
    int c, d, n, m, k;
    std::cin >> c >> d >> n >> m >> k;

    int remaining_winners = n * m - k;
    int main_round_problems = ceil((double)remaining_winners / n) * c;
    int additional_round_problems = ceil((double)remaining_winners / n) * d;

    int total_problems = main_round_problems + additional_round_problems;

    std::cout << total_problems << std::endl;

    return 0;
}
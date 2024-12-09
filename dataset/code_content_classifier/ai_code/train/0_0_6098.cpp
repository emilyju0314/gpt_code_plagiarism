#include <iostream>
#include <vector>

int main() {
    int n;
    std::cin >> n;

    std::vector<int> points(n);
    for (int i = 0; i < n; ++i) {
        std::cin >> points[i];
    }

    int first_score = 0, second_score = 0;
    bool first_wins = true;

    for (int i = 0; i < n; ++i) {
        if (points[i] > 0) {
            first_score += points[i];
        } else {
            second_score += (-1 * points[i]);
        }

        if (first_score > second_score) {
            first_wins = true;
        } else if (second_score > first_score) {
            first_wins = false;
        }
    }

    if (first_score == second_score) {
        if (points[n-1] > 0) {
            first_wins = true;
        } else {
            first_wins = false;
        }
    }

    if (first_wins) {
        std::cout << "first" << std::endl;
    } else {
        std::cout << "second" << std::endl;
    }

    return 0;
}
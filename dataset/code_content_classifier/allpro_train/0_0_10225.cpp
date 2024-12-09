#include <iostream>
#include <vector>
#include <algorithm>

int main() {
    int n, s, k;
    std::cin >> n >> s >> k;

    std::vector<int> candies(n);
    for (int i = 0; i < n; i++) {
        std::cin >> candies[i];
    }

    std::string colors;
    std::cin >> colors;

    int total_candies_eaten = 0;
    int total_seconds = 0;
    bool valid_solution = false;

    for (int i = s-1; i < n; i++) {
        total_candies_eaten += candies[i];
        total_seconds++;

        if (total_candies_eaten >= k) {
            valid_solution = true;
            break;
        }

        char prev_color = colors[i];

        for (int j = i+1; j < n; j++) {
            if (candies[j] > candies[j-1] && colors[j] != prev_color) {
                total_seconds += (j - i);
                total_candies_eaten += candies[j];
                i = j - 1;
                break;
            }
        }
    }

    if (valid_solution) {
        std::cout << total_seconds << std::endl;
    } else {
        std::cout << "-1" << std::endl;
    }

    return 0;
}
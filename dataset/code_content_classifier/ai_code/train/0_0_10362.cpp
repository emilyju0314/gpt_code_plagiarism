#include <iostream>
#include <vector>
#include <algorithm>

int main() {
    int n;
    std::cin >> n;

    std::string field;
    std::cin >> field;

    std::vector<int> packmen;
    std::vector<int> asterisks;
    
    for (int i = 0; i < n; i++) {
        if (field[i] == 'P') {
            packmen.push_back(i);
        } else if (field[i] == '*') {
            asterisks.push_back(i);
        }
    }

    int min_time = 0;

    for (int i = 0; i < asterisks.size(); i++) {
        int min_dist = n;
        for (int j = 0; j < packmen.size(); j++) {
            min_dist = std::min(min_dist, std::abs(asterisks[i] - packmen[j]));
        }
        min_time = std::max(min_time, min_dist);
    }

    std::cout << min_time << std::endl;

    return 0;
}
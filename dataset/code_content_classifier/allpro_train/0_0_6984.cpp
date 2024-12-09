#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>

int main() {
    int n;
    std::cin >> n;

    std::vector<int> seat_width(n);
    for (int i = 0; i < n; i++) {
        std::cin >> seat_width[i];
    }

    std::string passenger_order;
    std::cin >> passenger_order;

    std::vector<int> result(2*n);
    std::vector<std::pair<int, int>> introvert, extrovert;
    for (int i = 0; i < n; i++) {
        introvert.push_back({seat_width[i], i+1});
        extrovert.push_back({seat_width[i], i+1});
    }

    std::sort(introvert.begin(), introvert.end());
    std::sort(extrovert.rbegin(), extrovert.rend());

    std::unordered_map<int, int> taken;

    for (int i = 0; i < 2*n; i++) {
        if (passenger_order[i] == '0') {
            result[i] = introvert[0].second;
            taken[introvert[0].second] = 1;
            introvert.erase(introvert.begin());
        } else {
            result[i] = extrovert[0].second;
            if (taken.count(extrovert[0].second) == 1) {
                for (int j = 0; j < n; j++) {
                    if (taken.count(extrovert[j].second) == 0) {
                        result[i] = extrovert[j].second;
                        taken[extrovert[j].second] = 1;
                        break;
                    }
                }
            }
            extrovert.erase(extrovert.begin());
        }
    }

    for (int i = 0; i < 2*n; i++) {
        std::cout << result[i] << " ";
    }

    return 0;
}
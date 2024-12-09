#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>

int main() {
    int n;
    std::cin >> n;

    std::vector<int> a(n);
    std::unordered_map<int, std::vector<int>> positions;
    
    for (int i = 0; i < n; i++) {
        std::cin >> a[i];
        positions[a[i]].push_back(i);
    }

    std::vector<std::pair<int, int>> valid_x;
    
    for (auto& [key, value] : positions) {
        if (value.size() == 1) {
            valid_x.push_back(std::make_pair(key, 0));
        } else {
            bool is_arithmetic = true;
            int common_difference = value[1] - value[0];
            for (int i = 1; i < value.size(); i++) {
                if (value[i] - value[i-1] != common_difference) {
                    is_arithmetic = false;
                    break;
                }
            }
            if (is_arithmetic) {
                valid_x.push_back(std::make_pair(key, common_difference));
            }
        }
    }

    std::sort(valid_x.begin(), valid_x.end());

    std::cout << valid_x.size() << std::endl;
    for (auto& x : valid_x) {
        std::cout << x.first << " " << x.second << std::endl;
    }

    return 0;
}
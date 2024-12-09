#include <iostream>
#include <vector>
#include <algorithm>

int main() {
    std::vector<std::pair<int, int>> points(8);
    
    for (int i = 0; i < 8; i++) {
        std::cin >> points[i].first >> points[i].second;
    }
    
    std::sort(points.begin(), points.end());
    
    int x2 = points[3].first;
    int y2 = points[3].second;
    
    bool valid = true;
    for (const auto& p : points) {
        if (p.first == x2 && p.second == y2) {
            valid = false;
            break;
        }
    }
    
    if (valid) {
        std::cout << "respectable\n";
    } else {
        std::cout << "ugly\n";
    }
    
    return 0;
}
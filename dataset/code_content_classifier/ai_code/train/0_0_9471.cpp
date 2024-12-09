#include <iostream>
#include <map>
#include <set>
#include <string>

int main() {
    int n;
    std::cin >> n;

    std::map<int, std::set<int>> points; // Map to store points by x-coordinate

    for (int i = 0; i < n; i++) {
        std::string command;
        int x, y;
        std::cin >> command >> x >> y;

        if (command == "add") {
            points[x].insert(y); // Add the point to the set at the x-coordinate
        } else if (command == "remove") {
            points[x].erase(y); // Remove the point from the set at the x-coordinate
        } else if (command == "find") {
            int minX = INT_MAX;
            int minY = INT_MAX;
            bool found = false;

            for (auto it = points.upper_bound(x); it != points.end(); it++) {
                if (!(it->first > x)) continue;

                auto upper = it->second.upper_bound(y);
                if (upper != it->second.end()) {
                    found = true;
                    minX = it->first;
                    minY = std::min(minY, *upper);
                }
            }

            if (found) {
                std::cout << minX << " " << minY << std::endl;
            } else {
                std::cout << -1 << std::endl;
            }
        }
    }

    return 0;
}
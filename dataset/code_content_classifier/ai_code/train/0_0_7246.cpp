#include <iostream>
#include <string>
#include <set>

int main() {
    std::set<std::string> gems = {"Power", "Time", "Space", "Soul", "Reality", "Mind"};
    int n;
    std::cin >> n;

    std::set<std::string> seen_gems;

    for (int i = 0; i < n; i++) {
        std::string color;
        std::cin >> color;
        
        if (color == "purple") {
            seen_gems.insert("Power");
        } else if (color == "green") {
            seen_gems.insert("Time");
        } else if (color == "blue") {
            seen_gems.insert("Space");
        } else if (color == "orange") {
            seen_gems.insert("Soul");
        } else if (color == "red") {
            seen_gems.insert("Reality");
        } else if (color == "yellow") {
            seen_gems.insert("Mind");
        }
    }

    std::cout << 6 - seen_gems.size() << std::endl;

    for (const std::string& gem : gems) {
        if (seen_gems.find(gem) == seen_gems.end()) {
            std::cout << gem << std::endl;
        }
    }

    return 0;
}
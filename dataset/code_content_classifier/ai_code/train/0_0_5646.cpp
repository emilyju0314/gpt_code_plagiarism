#include <iostream>
#include <string>
#include <unordered_set>

int main() {
    int t;
    std::cin >> t;

    while (t--) {
        std::string path;
        std::cin >> path;

        int time = 0;
        std::unordered_set<std::pair<int, int>> visited;

        int x = 0, y = 0;
        for (char c : path) {
            std::pair<int, int> current = {x, y};
            if (visited.count(current) == 0) {
                visited.insert(current);
                time += 5;
            } else {
                time++;
            }

            if (c == 'S') y--;
            else if (c == 'N') y++;
            else if (c == 'W') x--;
            else if (c == 'E') x++;
        }

        std::cout << time << std::endl;
    }

    return 0;
}
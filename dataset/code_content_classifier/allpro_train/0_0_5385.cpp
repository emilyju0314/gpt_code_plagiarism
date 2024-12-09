#include <iostream>
#include <string>
#include <algorithm>

int main() {
    std::string commands;
    int n;
    std::cin >> commands >> n;

    int maxDistance = 0;

    for (int i = 0; i < commands.size(); ++i) {
        std::string modifiedCommands = commands;
        if (n > 0) {
            modifiedCommands[i] = (commands[i] == 'T' ? 'F' : 'T');
            n--;
        }

        int distance = 0;
        int x = 0;
        int y = 0;
        int dx = 0;
        int dy = 1;

        for (char command : modifiedCommands) {
            if (command == 'F') {
                x += dx;
                y += dy;
            } else {
                int temp = dx;
                dx = -dy;
                dy = temp;
            }
        }

        distance = std::abs(x) + std::abs(y);
        maxDistance = std::max(maxDistance, distance);
    }

    std::cout << maxDistance << std::endl;

    return 0;
}
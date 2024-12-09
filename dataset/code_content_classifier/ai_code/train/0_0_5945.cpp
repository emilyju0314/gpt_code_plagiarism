#include <iostream>
#include <string>

int main() {
    std::string s;
    std::cin >> s;

    bool possible = false;
    int n = s.size();

    for (int i = 0; i < n; i++) {
        int colors[3] = {0}; // Index 0: A, Index 1: B, Index 2: C
        if (s[i] == 'A') colors[0]++;
        else if (s[i] == 'B') colors[1]++;
        else if (s[i] == 'C') colors[2]++;

        if (i > 0) {
            for (int j = 0; j < 3; j++) {
                colors[j] += colors[j - 1];
                colors[j] = std::min(colors[j], 1);
            }
        }

        if (colors[0] && colors[1] && colors[2]) {
            possible = true;
            break;
        }
    }

    if (possible) {
        std::cout << "Yes" << std::endl;
    } else {
        std::cout << "No" << std::endl;
    }

    return 0;
}
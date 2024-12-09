#include <iostream>
#include <string>

int main() {
    int n, d;
    std::cin >> n >> d;

    std::string s;
    std::cin >> s;

    int jumps = 0;
    int current_position = 0;
    while (current_position < n - 1) {
        int next_position = current_position + d;
        bool found = false;
        for (int i = next_position; i > current_position; i--) {
            if (s[i] == '1') {
                found = true;
                jumps++;
                current_position = i;
                break;
            }
        }
        if (!found) {
            std::cout << -1 << std::endl;
            return 0;
        }
    }

    std::cout << jumps << std::endl;

    return 0;
}
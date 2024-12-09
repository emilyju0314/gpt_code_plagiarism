#include <iostream>
#include <string>
#include <unordered_map>

int main() {
    int t;
    std::cin >> t;

    while(t--) {
        std::string keyboard, word;
        std::cin >> keyboard >> word;

        std::unordered_map<char, int> positions;
        for(int i = 0; i < keyboard.size(); i++) {
            positions[keyboard[i]] = i;
        }

        int total_time = 0;
        int prev_pos = 0;

        for(char c : word) {
            total_time += abs(positions[c] - prev_pos);
            prev_pos = positions[c];
        }

        std::cout << total_time << std::endl;
    }

    return 0;
}
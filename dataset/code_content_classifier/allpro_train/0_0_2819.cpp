#include <iostream>
#include <vector>
#include <string>

int main() {
    int n;
    std::cin >> n;

    std::vector<std::string> strings(n);
    for(int i = 0; i < n; i++) {
        std::cin >> strings[i];
    }

    int min_moves = 0;
    for(int i = 0; i < strings[0].size(); i++) {
        std::string target = strings[0].substr(i) + strings[0].substr(0, i);
        int moves = 0;
        for(int j = 1; j < n; j++) {
            int k = 0;
            while(k < strings[j].size() && strings[j] != target) {
                target = target.substr(1) + target[0];
                moves++;
                k++;
            }

            if(k == strings[j].size() && strings[j] != target) {
                std::cout << -1 << std::endl;
                return 0;
            }
        }

        min_moves = (i == 0) ? moves : std::min(min_moves, moves);
    }

    std::cout << min_moves << std::endl;

    return 0;
}
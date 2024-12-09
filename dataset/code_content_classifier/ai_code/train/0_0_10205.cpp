#include <iostream>
#include <vector>

int main() {
    int N;
    std::cin >> N;

    std::vector<std::pair<int, int>> black_squares;

    for(int i = 0; i < N; i += 2) {
        for(int j = 0; j < N; j += 2) {
            black_squares.push_back({i, j});
        }
    }

    std::cout << black_squares.size() << std::endl;
    for(auto square : black_squares) {
        std::cout << square.first << " " << square.second << std::endl;
    }

    return 0;
}
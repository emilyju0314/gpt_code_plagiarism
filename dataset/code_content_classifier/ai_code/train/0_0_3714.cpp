#include <iostream>
#include <vector>

int main() {
    int n;

    while (std::cin >> n) {
        if (n == 0) {
            break;
        }

        int white_count = 0;
        std::vector<int> stones;

        for (int i = 0; i < n; i++) {
            int color;
            std::cin >> color;
            stones.push_back(color);
        }

        for (int i = 0; i < n; i++) {
            if (i % 2 == 0) {
                if (stones[i] == 0) {
                    white_count++;
                }
            } else {
                if (stones[i] == stones.back()) {
                    // do nothing
                } else {
                    while (!stones.empty() && stones.back() == 0) {
                        stones.pop_back();
                    }
                }
            }
        }

        std::cout << white_count << std::endl;
    }

    return 0;
}
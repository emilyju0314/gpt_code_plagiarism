#include <iostream>
#include <vector>
#include <map>
#include <cmath>
#include <algorithm>

struct Robot {
    std::string nickname;
    int x, y;
    int vx, vy;
};

int main() {
    int N, T, R;
    
    while (std::cin >> N >> T >> R && N != 0 && T != 0 && R != 0) {
        std::vector<Robot> robots(N);
        std::map<std::string, std::vector<int>> dataExchange;

        for (int i = 0; i < N; ++i) {
            std::cin >> robots[i].nickname;
            std::cin >> robots[i].x >> robots[i].y;
            robots[i].vx = robots[i].vy = 0;
        }

        for (int t = 1; t <= T; ++t) {
            for (int i = 0; i < N; ++i) {
                std::cin >> robots[i].vx >> robots[i].vy;
                robots[i].x += robots[i].vx;
                robots[i].y += robots[i].vy;
            }

            for (int i = 0; i < N; ++i) {
                for (int j = 0; j < N; ++j) {
                    if (i != j) {
                        int dist = std::pow(robots[i].x - robots[j].x, 2) + std::pow(robots[i].y - robots[j].y, 2);
                        if (dist <= R * R) {
                            dataExchange[robots[j].nickname].push_back(t);
                        }
                    }
                }
            }
        }

        std::vector<std::string> output;

        for (const auto& it : dataExchange) {
            std::sort(it.second.begin(), it.second.end());
            if (it.second.back() == T) {
                output.push_back(it.first);
            }
        }

        std::sort(output.begin(), output.end());

        for (const auto& nickname : output) {
            std::cout << nickname << std::endl;
        }
    }

    return 0;
}
#include <iostream>
#include <unordered_map>
#include <vector>
#include <cstring>

int main() {
    int N, W;
    while (std::cin >> N >> W) {
        if (N == 0 && W == 0) break;

        std::unordered_map<std::string, int> days = {
            {"Sunday", 0},
            {"Monday", 1},
            {"Tuesday", 2},
            {"Wednesday", 3},
            {"Thursday", 4},
            {"Friday", 5},
            {"Saturday", 6}
        };

        bool can_finish = true;

        for (int i = 0; i < N; i++) {
            int t, c;
            std::cin >> t >> c;
            std::vector<int> convenient_days(c);
            for (int j = 0; j < c; j++) {
                std::string day;
                std::cin >> day;
                convenient_days[j] = days[day];
            }

            int total_lessons = t * c;
            int min_days = (total_lessons + 6) / 7; // min days needed to finish all lessons
            if (min_days > W) {
                can_finish = false;
            }
        }

        if (can_finish) {
            std::cout << "Yes\n";
        } else {
            std::cout << "No\n";
        }
    }

    return 0;
}
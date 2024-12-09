#include <iostream>
#include <vector>
#include <algorithm>

int main() {
    int n, m, k;
    std::cin >> n >> m >> k;

    std::vector<std::vector<int>> lessons(n, std::vector<int>(m));

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            char lesson;
            std::cin >> lesson;
            lessons[i][j] = lesson - '0';
        }
    }

    int result = 0;
    int totalLessons = n * m;

    for (int mask = 0; mask < (1 << totalLessons); mask++) {
        int skippedLessons = __builtin_popcount(mask);
        if (skippedLessons > k) continue;

        int currentHours = 0;
        for (int i = 0; i < n; i++) {
            int currentDayHours = 0;
            for (int j = 0; j < m; j++) {
                if ((mask & (1 << (i*m + j))) == 0) {
                    currentDayHours++;
                }
                else {
                    currentHours += currentDayHours;
                    currentDayHours = 0;
                }
            }
            currentHours += currentDayHours;
        }

        result = std::max(result, currentHours);
    }

    std::cout << result << std::endl;

    return 0;
}
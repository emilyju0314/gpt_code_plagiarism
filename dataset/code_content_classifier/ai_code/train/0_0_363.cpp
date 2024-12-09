#include <iostream>
#include <vector>
#include <unordered_map>

int main() {
    int n, m;
    long long k;
    std::cin >> n >> m >> k;

    std::vector<int> colors1(n), colors2(m);
    for (int i = 0; i < n; i++) {
        std::cin >> colors1[i];
    }
    for (int i = 0; i < m; i++) {
        std::cin >> colors2[i];
    }

    std::unordered_map<int, int> lastSeen1, lastSeen2;
    int sameDays = 0;
    long long day = 1;
    while (true) {
        int color1 = colors1[(day - 1) % n];
        int color2 = colors2[(day - 1) % m];

        if (color1 == color2) {
            sameDays = 0;
        } else {
            sameDays++;
        }

        if (sameDays == k) {
            std::cout << day << std::endl;
            break;
        }

        day++;
    }

    return 0;
}
#include <iostream>

int main() {
    int n, t;
    std::cin >> n >> t;

    int glasses[11][11] = {0};
    glasses[1][1] = t;

    int fullGlasses = 0;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= i; j++) {
            if (glasses[i][j] > 1) {
                int overflow = glasses[i][j] - 1;
                glasses[i][j] = 1;
                glasses[i + 1][j] += overflow / 2;
                glasses[i + 1][j + 1] += overflow / 2;
            }
            if (glasses[i][j] == 1) {
                fullGlasses++;
            }
        }
    }

    std::cout << fullGlasses << std::endl;

    return 0;
}
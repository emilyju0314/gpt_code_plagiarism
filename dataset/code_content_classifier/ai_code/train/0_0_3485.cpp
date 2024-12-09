#include <iostream>
#include <cmath>

int main() {
    int t;
    std::cin >> t;

    for (int i = 0; i < t; i++) {
        int x[4], y[4];
        for (int j = 0; j < 4; j++) {
            std::cin >> x[j] >> y[j];
        }

        int min_steps = INT_MAX;
        for (int j = 0; j < 4; j++) {
            for (int k = 0; k < 4; k++) {
                for (int l = 0; l < 4; l++) {
                    for (int m = 0; m < 4; m++) {
                        int xi = x[0] + j;
                        int yi = y[0] + k;

                        int xj = x[1] + l;
                        int yj = y[1] + m;

                        int xk = x[2] - j;
                        int yk = y[2] - k;

                        int xl = x[3] - l;
                        int yl = y[3] - m;

                        if ((xi == xj && yi == yl) && (xk == xj && yk == yi)) {
                            int steps = abs(j) + abs(k) + abs(l) + abs(m);
                            min_steps = std::min(min_steps, steps);
                        }
                    }
                }
            }
        }

        std::cout << min_steps << std::endl;
    }

    return 0;
}
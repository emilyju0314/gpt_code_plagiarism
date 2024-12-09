#include <iostream>
#include <cmath>

int main() {
    int T;
    std::cin >> T;

    for (int t = 0; t < T; t++) {
        double R, L;
        std::cin >> R >> L;

        int N;
        std::cin >> N;

        double sum_V = 0;
        for (int i = 0; i < N; i++) {
            double theta, V;
            std::cin >> theta >> V;
            sum_V += V;
        }

        double base_straight = L - sum_V / (M_PI * R * R);
        double base_curved = 2 * M_PI * R;

        std::cout << base_straight << " " << base_curved << std::endl;
    }

    return 0;
}
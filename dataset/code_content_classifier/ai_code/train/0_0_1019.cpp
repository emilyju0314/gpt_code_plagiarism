#include <iostream>
#include <vector>
#include <cmath>

int main() {
    int N, L;
    std::cin >> N >> L;

    std::vector<int> T(N);
    for(int i = 0; i < N; ++i) {
        std::cin >> T[i];
    }

    double sum_x = 0, sum_y = 0;
    for(int i = 0; i < N; ++i) {
        for(int j = i+1; j < N; ++j) {
            int d1 = T[j] - T[i];
            int d2 = (T[j] - T[i] + L) % L;
            sum_x += std::cos(2*M_PI * (T[i] + d1/3.0) / L) + std::cos(2*M_PI * (T[i] + d2/3.0) / L);
            sum_y += std::sin(2*M_PI * (T[i] + d1/3.0) / L) + std::sin(2*M_PI * (T[i] + d2/3.0) / L);
        }
    }

    double center_x = sum_x / (N * (N-1) / 6);
    double center_y = sum_y / (N * (N-1) / 6);

    std::cout << center_x << " " << center_y << std::endl;

    return 0;
}
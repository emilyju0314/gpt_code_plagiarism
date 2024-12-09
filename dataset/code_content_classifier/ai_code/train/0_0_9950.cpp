#include <iostream>
#include <vector>
#include <algorithm>

struct Robot {
    double p_no_weak;
    int id_weak;
    double p_weak;
};

int main() {
    int n;
    while (std::cin >> n && n != 0) {
        std::vector<Robot> robots(n);
        for (int i = 0; i < n; i++) {
            std::cin >> robots[i].p_no_weak >> robots[i].id_weak >> robots[i].p_weak;
        }

        std::vector<double> expected_time(n + 1, 0);
        std::vector<int> combinations(n + 1, 0);

        for (int i = 1; i <= n; i++) {
            expected_time[i] = 1.0;
            combinations[i] = 1;
        }

        for (int i = 1; i < n; i++) {
            int id = robots[i].id_weak;
            double p_sum_weak = robots[i].p_no_weak + robots[i].p_weak;

            for (int j = n; j >= 1; j--) {
                expected_time[j + 1] += expected_time[j] * p_sum_weak;
                combinations[j + 1] += combinations[j];
                expected_time[j] = expected_time[j] * (1 - p_sum_weak);

                if (id == i) {
                    expected_time[2] += expected_time[1] * p_sum_weak;
                    combinations[2] += combinations[1];
                    expected_time[1] = expected_time[1] * (1 - p_sum_weak);
                }
            }
        }

        long long remainder = combinations[n] % 1000000007;
        std::cout << expected_time[n] << " " << remainder << std::endl;
    }

    return 0;
}
#include <iostream>
#include <vector>
#include <algorithm>

int main() {
    int n;

    while (std::cin >> n && n != 0) {
        std::vector<int> times(n);
        for (int i = 0; i < n; i++) {
            std::cin >> times[i];
        }

        std::sort(times.begin(), times.end());

        int total_waiting_time = 0;
        int current_time = times[0];
        for (int i = 1; i < n; i++) {
            current_time += times[i];
            total_waiting_time += current_time;
        }

        std::cout << total_waiting_time << std::endl;
    }

    return 0;
}
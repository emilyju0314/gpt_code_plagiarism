#include <iostream>
#include <vector>

int main() {
    int n, m;
    std::cin >> n >> m;

    std::vector<int> s(n), f(n), t(n);
    for (int i = 0; i < n; i++) {
        std::cin >> s[i] >> f[i] >> t[i];
    }

    for (int i = 0; i < n; i++) {
        int time = t[i];
        int dest = f[i];
        int start = s[i];

        if (dest == start) {
            std::cout << time << std::endl;
        } else {
            int cycle_time = 2 * (m - 1);
            int dest_time = dest > start ? dest - 1 : m - dest + m - 1;

            int time_to_cycle = (time % cycle_time == start - 1) ? 0 : (start - 1 - time % cycle_time + cycle_time) % cycle_time;

            if (time_to_cycle + cycle_time * ((time_to_cycle < dest_time) ? 1 : 0) + dest_time >= m - 1) {
                std::cout << time + time_to_cycle + dest_time << std::endl;
            } else {
                std::cout << time + time_to_cycle + dest_time + cycle_time << std::endl;
            }
        }
    }

    return 0;
}
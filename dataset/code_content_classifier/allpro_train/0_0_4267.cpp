#include <iostream>
#include <cmath>

int main() {
    int t;
    std::cin >> t;

    for (int i = 0; i < t; i++) {
        int a, b, c, d;
        std::cin >> a >> b >> c >> d;

        if (a > b * c) {
            std::cout << -1 << std::endl;
        } else {
            long long max_health = a;
            long long total_damage = a;
            long long total_heal = 0;

            for (int j = 1; j <= c; j++) {
                long long damage_to_apply = std::min(total_damage, total_heal);
                total_damage -= damage_to_apply;
                total_heal -= damage_to_apply;

                max_health = std::max(max_health, total_heal);

                if (j < c) {
                    total_damage += a;
                    total_heal += b * j;
                }
            }

            long long cycles = (max_health + a - 1) / a;
            long long answer = max_health + (cycles - 1) * d;

            std::cout << answer << std::endl;
        }
    }

    return 0;
}
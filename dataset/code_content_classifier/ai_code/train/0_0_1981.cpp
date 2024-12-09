#include <iostream>
#include <string>

int main() {
    int n;

    while (true) {
        std::cin >> n;
        if (n == 0) {
            break;
        }

        int lunch = 0, dinner = 0, midnight = 0;
        int lunch_ok = 0, dinner_ok = 0, midnight_ok = 0;

        for (int i = 0; i < n; i++) {
            int check_hour, check_minute, provide_minute;
            scanf("%d:%d %d", &check_hour, &check_minute, &provide_minute);

            if ((check_hour >= 11 && check_hour <= 14) || (check_hour == 15 && check_minute == 0)) {
                lunch++;
                if (provide_minute <= 8) {
                    lunch_ok++;
                }
            } else if (check_hour >= 18 && check_hour <= 20) {
                dinner++;
                if (provide_minute <= 8) {
                    dinner_ok++;
                }
            } else if ((check_hour >= 21 && check_hour <= 23) || (check_hour >= 0 && check_hour <= 1)) {
                midnight++;
                if (provide_minute <= 8) {
                    midnight_ok++;
                }
            }
        }

        std::cout << "lunch " << (lunch == 0 ? "no guest" : std::to_string((lunch_ok * 100) / lunch)) << std::endl;
        std::cout << "dinner " << (dinner == 0 ? "no guest" : std::to_string((dinner_ok * 100) / dinner)) << std::endl;
        std::cout << "midnight " << (midnight == 0 ? "no guest" : std::to_string((midnight_ok * 100) / midnight)) << std::endl;
    }

    return 0;
}
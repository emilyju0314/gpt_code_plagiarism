#include <iostream>
#include <vector>
#include <iomanip>

int main() {
    int n, p, q;
    std::cin >> n >> p >> q;

    std::vector<std::pair<int, int>> projects(n);
    for (int i = 0; i < n; i++) {
        std::cin >> projects[i].first >> projects[i].second;
    }

    double min_days = 1e18;
    for (int i = 0; i <= n; i++) {
        double left_days = 0;
        if (i > 0) {
            left_days = (double)p / projects[i-1].first;
        }
        
        double right_days = 1e18;
        int exp_sum = 0;
        int money_sum = 0;
        for (int j = i; j < n; j++) {
            exp_sum += projects[j].first;
            money_sum += projects[j].second;
            right_days = std::min(right_days, (double)(q - money_sum) / projects[j].second);
            if (exp_sum >= p) {
                right_days = std::min(right_days, (double)(p - (exp_sum - projects[j].first)) / projects[j].first);
                break;
            }
        }

        min_days = std::min(min_days, left_days + right_days);
    }

    std::cout << std::fixed << std::setprecision(10) << min_days << std::endl;

    return 0;
}
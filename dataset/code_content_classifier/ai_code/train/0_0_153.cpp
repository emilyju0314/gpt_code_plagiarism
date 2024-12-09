#include <iostream>
#include <vector>

int main() {
    int L;
    while (std::cin >> L && L != 0) {
        std::vector<std::pair<int, int>> savings;
        int total_savings = 0;

        for (int i = 0; i < 12; i++) {
            int M, N;
            std::cin >> M >> N;
            savings.push_back({M, N});
        }

        int months = 0;
        bool reached = false;

        for (int i = 0; i < 12; i++) {
            total_savings += savings[i].first - savings[i].second;
            if (total_savings >= L) {
                months = i + 1;
                reached = true;
                break;
            }
        }

        if (reached) {
            std::cout << months << std::endl;
        } else {
            std::cout << "NA" << std::endl;
        }
    }

    return 0;
}
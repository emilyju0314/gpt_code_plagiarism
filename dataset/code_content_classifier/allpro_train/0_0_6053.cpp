#include <iostream>
#include <vector>

int main() {
    int n, m;

    while (std::cin >> n >> m) {
        if (n == 0 && m == 0) {
            break;
        }

        std::vector<int> applicants(n);
        for (int i = 0; i < n; i++) {
            std::cin >> applicants[i];
        }

        int min_work_time = 1001;
        int count = 0;
        for (int i = n - 1; i >= 0; i--) {
            if (applicants[i] < min_work_time) {
                min_work_time = applicants[i];
                count = 1;
            } else if (applicants[i] == min_work_time) {
                count++;
            }

            if (min_work_time * count <= m) {
                std::cout << i + 1 << std::endl;
                break;
            }
        }
    }

    return 0;
}
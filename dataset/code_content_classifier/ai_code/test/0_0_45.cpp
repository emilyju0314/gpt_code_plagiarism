#include <iostream>
#include <vector>

int main() {
    int t;
    std::cin >> t;

    while (t--) {
        int n;
        std::cin >> n;

        std::vector<int> days(n);
        for (int i = 0; i < n; i++) {
            std::cin >> days[i];
        }

        int height = 1;
        int consecutive_unwatered = 0;

        for (int i = 0; i < n; i++) {
            if (days[i] == 1) {
                if (consecutive_unwatered == 1) {
                    height += 5;
                } else {
                    height += 1;
                }
                consecutive_unwatered = 0;
            } else {
                consecutive_unwatered++;
            }

            if (consecutive_unwatered == 2) {
                std::cout << "-1" << std::endl;
                break;
            }
        }

        if (consecutive_unwatered < 2) {
            std::cout << height << std::endl;
        }
    }

    return 0;
}
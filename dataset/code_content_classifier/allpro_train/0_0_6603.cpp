#include <iostream>
#include <vector>

int main() {
    int t;
    std::cin >> t;

    for (int i = 0; i < t; i++) {
        int x;
        std::cin >> x;

        std::vector<int> digits;
        
        int sum = 0;
        for (int j = 1; j <= 9; j++) {
            if (sum + j <= x) {
                digits.push_back(j);
                sum += j;
            } else {
                break;
            }
        }

        if (sum == x) {
            for (int j = digits.size() - 1; j >= 0; j--) {
                std::cout << digits[j];
            }
            std::cout << "\n";
        } else {
            std::cout << "-1\n";
        }
    }

    return 0;
}
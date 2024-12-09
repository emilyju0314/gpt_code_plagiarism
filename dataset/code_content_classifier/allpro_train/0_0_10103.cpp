#include <iostream>
#include <string>
#include <vector>

int main() {
    int n;
    std::cin >> n;

    std::string s;
    std::cin >> s;

    for (int i = 1; i < n; i++) {
        if (n % i != 0) continue;

        std::vector<int> nums(n, 0);

        bool possible = true;
        for (int j = 0; j < n; j++) {
            int diff = s[j] - '0';
            if (diff != 0) {
                int start = j;
                for (int k = 0; k < n / i; k++) {
                    nums[start] += diff;
                    start = (start + i) % n;
                }
            }
        }

        for (int j : nums) {
            if (j % n != 0) {
                possible = false;
                break;
            }
        }

        if (possible) {
            std::cout << "YES" << std::endl;
            return 0;
        }
    }

    std::cout << "NO" << std::endl;

    return 0;
}
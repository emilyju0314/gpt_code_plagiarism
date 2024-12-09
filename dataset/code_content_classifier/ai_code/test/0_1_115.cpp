#include <iostream>
#include <vector>

int main() {
    int t;
    std::cin >> t;

    while (t--) {
        int n;
        long long h;
        std::cin >> n >> h;

        std::vector<int> attacks(n);
        for (int i = 0; i < n; i++) {
            std::cin >> attacks[i];
        }

        int left = 1, right = n;
        while (left < right) {
            int mid = (left + right) / 2;
            std::vector<int> temp(attacks.begin(), attacks.begin() + mid);
            std::sort(temp.begin(), temp.end());

            long long count = 0;
            for (int i = 0; i < mid; i++) {
                count += (temp[i] - i);
            }

            if (count >= h) {
                right = mid;
            } else {
                left = mid + 1;
            }
        }

        std::cout << left << std::endl;
    }

    return 0;
}
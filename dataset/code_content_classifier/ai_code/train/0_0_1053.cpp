#include <iostream>
#include <vector>

int main() {
    int n, x, y;
    std::cin >> n >> x >> y;

    std::vector<int> days(n);
    for (int i = 0; i < n; i++) {
        std::cin >> days[i];
    }

    int ans = -1;
    for (int i = 0; i < n; i++) {
        bool valid = true;

        for (int j = i - x; j < i; j++) {
            if (j >= 0 && days[i] >= days[j]) {
                valid = false;
                break;
            }
        }

        for (int j = i + 1; j <= i + y; j++) {
            if (j < n && days[i] >= days[j]) {
                valid = false;
                break;
            }
        }

        if (valid) {
            ans = i + 1;
            break;
        }
    }

    std::cout << ans << std::endl;

    return 0;
}
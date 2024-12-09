#include <iostream>
#include <vector>

int main() {
    int n;
    std::cin >> n;

    std::vector<int> sequence(n);
    for (int i = 0; i < n; ++i) {
        std::cin >> sequence[i];
    }

    int sum = 0;
    bool found_odd = false;
    int max_odd = -1e5;

    for (int i = 0; i < n; ++i) {
        if (sequence[i] % 2 != 0) {
            found_odd = true;
            sum += sequence[i];
            if (sequence[i] > max_odd) {
                max_odd = sequence[i];
            }
        }
    }

    if (found_odd) {
        if (sum % 2 != 0) {
            std::cout << sum << std::endl;
        } else {
            std::cout << sum - max_odd << std::endl;
        }
    }

    return 0;
}
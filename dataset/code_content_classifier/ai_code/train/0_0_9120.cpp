#include <iostream>
#include <vector>

int main() {
    int n, k;
    std::cin >> n >> k;

    std::vector<int> r(2 * n + 1);
    for(int i = 0; i < 2 * n + 1; i++) {
        std::cin >> r[i];
    }

    for(int i = 1; i < 2 * n - 1 && k > 0; i += 2) {
        if(r[i] - 1 > r[i - 1] && r[i] - 1 > r[i + 1]) {
            r[i]--;
            k--;
        }
    }

    for(int i = 0; i < 2 * n + 1; i++) {
        std::cout << r[i] << " ";
    }

    return 0;
}
#include <iostream>
#include <algorithm>

int main() {
    int L, R;
    std::cin >> L >> R;

    int ans = 2018;
    for (int i = L; i < R; ++i) {
        for (int j = i + 1; j <= R; ++j) {
            ans = std::min(ans, (i*j) % 2019);
        }
    }

    std::cout << ans << std::endl;

    return 0;
}
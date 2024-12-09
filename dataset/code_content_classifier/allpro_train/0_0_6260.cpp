#include <iostream>
#include <vector>

const long long MOD = 1000000007;

int main() {
    int w, h;
    std::cin >> w >> h;

    long long ans = 0;
    for (int x1 = 0; x1 <= w; x1++) {
        for (int y1 = 0; y1 <= h; y1++) {
            for (int x2 = x1; x2 <= w; x2++) {
                for (int y2 = 0; y2 <= h; y2++) {
                    int area = (x1 * y2 - x2 * y1 + w * (y1 - y2) + h * (x2 - x1));
                    if (area % 2 == 0 && area != 0) {
                        ans = (ans + 1) % MOD;
                    }
                }
            }
        }
    }

    std::cout << ans << std::endl;

    return 0;
}
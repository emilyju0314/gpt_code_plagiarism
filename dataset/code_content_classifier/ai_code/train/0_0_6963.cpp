#include <iostream>
#include <bitset>
#include <vector>
#include <algorithm>

int setBits(int x) {
    std::bitset<64> bits(x);
    return bits.count();
}

int main() {
    int n;
    std::cin >> n;

    for (int i = 0; i < n; i++) {
        long long l, r;
        std::cin >> l >> r;

        if (l == 0) {
            std::cout << 1 << std::endl;
            continue;
        }

        int highest = 0;
        long long ans = 0;
        for (int j = 63; j >= 0; j--) {
            if ((r & (1LL << j)) == 0) {
                continue;
            }

            long long cur = (1LL << j) - 1;
            for (int k = j - 1; k >= 0; k--) {
                if ((r & (1LL << k)) != 0) {
                    cur |= (1LL << k);
                }
            }

            if (cur >= l) {
                int bits = setBits(cur);
                if (bits > highest) {
                    highest = bits;
                    ans = cur;
                }
            }
        }

        std::cout << ans << std::endl;
    }

    return 0;
}
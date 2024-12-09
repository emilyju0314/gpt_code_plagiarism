#include <iostream>
#include <vector>

int main() {
    int k, q;
    std::cin >> k >> q;

    std::vector<long long> d(k);
    for (int i = 0; i < k; i++) {
        std::cin >> d[i];
    }

    for (int i = 0; i < q; i++) {
        long long n, x, m;
        std::cin >> n >> x >> m;

        long long count = 0;
        long long prev = x;
        for (long long j = 1; j < n; j++) {
            long long aj = (prev + d[(j - 1) % k]) % m;
            long long aj1 = (aj + d[j % k]) % m;
            if (aj < aj1) {
                count++;
            }
            prev = aj;
        }

        std::cout << count << std::endl;
    }

    return 0;
}
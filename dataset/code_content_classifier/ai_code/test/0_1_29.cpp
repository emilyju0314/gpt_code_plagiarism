#include <iostream>
#include <vector>
#include <cmath>

int main() {
    int t;
    std::cin >> t;

    while(t--) {
        int n;
        std::cin >> n;

        std::vector<long long> a(n);
        for(int i = 0; i < n; i++) {
            std::cin >> a[i];
        }

        long long s = 0;
        for(int i = 0; i < n; i++) {
            s += a[i];
        }

        int count = 0;
        for(int mask = 1; mask < (1 << n); mask++) {
            long long sum = 0;
            for(int i = 0; i < n; i++) {
                if(mask & (1 << i)) {
                    sum += a[i];
                }
            }

            if(sum == s - 1) {
                count++;
            }
        }

        std::cout << count << std::endl;
    }

    return 0;
}
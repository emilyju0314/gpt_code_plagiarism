#include <iostream>
#include <vector>
#include <cmath>

const int MOD = 1000000007;

int main() {
    int n;
    std::cin >> n;

    std::vector<int> c(n);
    for(int i = 0; i < n; i++) {
        std::cin >> c[i];
    }

    std::vector<int> b(n-1);
    for(int i = 0; i < n-1; i++) {
        std::cin >> b[i];
    }

    int q;
    std::cin >> q;

    while(q--) {
        int x;
        std::cin >> x;

        int countGoodArrays = 0;

        // Iterate through all possible arrays a
        std::vector<int> a(n);
        do {
            bool isGoodArray = true;

            // Simulate the process on array a
            for(int j = 0; j < n-1; j++) {
                a[j] = std::min(a[j], (a[j] + a[j+1] - b[j]) / 2);
                a[j+1] = std::max(a[j+1], (a[j] + a[j+1] + b[j]) / 2);

                if(a[j] < 0 || a[j] > c[j] || a[j+1] < 0 || a[j+1] > c[j+1]) {
                    isGoodArray = false;
                    break;
                }
            }

            if(isGoodArray && a[0] >= x) {
                countGoodArrays = (countGoodArrays + 1) % MOD;
            }

        } while(std::next_permutation(a.begin(), a.end()));

        std::cout << countGoodArrays << std::endl;        
    }

    return 0;
}
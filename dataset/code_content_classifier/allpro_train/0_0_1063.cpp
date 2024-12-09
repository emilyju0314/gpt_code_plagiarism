#include <iostream>
#include <vector>
#include <algorithm>

int gcd(int a, int b) {
    if (b == 0) {
        return a;
    }
    return gcd(b, a % b);
}

int main() {
    int t;
    std::cin >> t;

    while (t--) {
        int n;
        std::cin >> n;

        std::vector<int> a(n);
        for (int i = 0; i < n; i++) {
            std::cin >> a[i];
        }

        std::sort(a.begin(), a.end(), std::greater<int>());

        int curr_gcd = a[0];
        std::vector<int> b;
        b.push_back(a[0]);

        for (int i = 1; i < n; i++) {
            int candidate = -1;
            int max_gcd = 0;

            for (int j = 0; j < n; j++) {
                if (std::find(b.begin(), b.end(), a[j]) == b.end()) {
                    int new_gcd = gcd(curr_gcd, a[j]);
                    if (new_gcd > max_gcd) {
                        max_gcd = new_gcd;
                        candidate = a[j];
                    }
                }
            }

            b.push_back(candidate);
            curr_gcd = max_gcd;
        }

        for (int i = 0; i < n; i++) {
            std::cout << b[i] << " ";
        }
        std::cout << std::endl;
    }

    return 0;
}
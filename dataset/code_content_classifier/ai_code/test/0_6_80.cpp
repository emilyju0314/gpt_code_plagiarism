#include <iostream>
#include <vector>
#include <algorithm>
#include <map>

int main() {
    int t;
    std::cin >> t;

    while (t--) {
        int n, m;
        std::cin >> n >> m;

        std::vector<int> a(n), b(m);
        for (int i = 0; i < n; i++) {
            std::cin >> a[i];
        }
        for (int i = 0; i < m; i++) {
            std::cin >> b[i];
        }

        std::map<int, int> freq;
        for (int i = 0; i < n; i++) {
            freq[a[i]] = i;
        }

        long long inversions = 0;
        for (int i = 0; i < m; i++) {
            inversions += freq.upper_bound(b[i])->second;
        }

        std::cout << inversions << std::endl;
    }

    return 0;
}
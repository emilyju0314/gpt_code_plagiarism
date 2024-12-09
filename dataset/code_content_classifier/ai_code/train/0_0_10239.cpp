#include <iostream>
#include <vector>
#include <algorithm>

int main() {
    int t;
    std::cin >> t;

    while(t--) {
        int n, k;
        std::cin >> n >> k;

        std::vector<int> a(n);
        std::vector<int> b(n);

        for(int i = 0; i < n; i++) {
            std::cin >> a[i];
        }

        for(int i = 0; i < n; i++) {
            std::cin >> b[i];
        }

        std::sort(a.begin(), a.end());
        std::sort(b.rbegin(), b.rend());

        int sum = 0;
        int swaps = 0;
        
        for(int i = 0; i < n; i++) {
            if(swaps < k && a[i] < b[i]) {
                sum += b[i];
                swaps++;
            } else {
                sum += a[i];
            }
        }

        std:: cout << sum << std::endl;
    }

    return 0;
}
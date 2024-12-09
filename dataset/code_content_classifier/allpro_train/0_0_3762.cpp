#include <iostream>
#include <algorithm>
#include <vector>

int main() {
    int n, k;
    std::cin >> n >> k;

    std::vector<int> a(n);
    for(int i = 0; i < n; i++) {
        std::cin >> a[i];
    }

    std::vector<int> b = a;
    std::sort(b.begin(), b.end());

    int max_m = b[n-1];
    for(int i = 0; i < std::min(n, k+1); i++) {
        for(int j = 0; j < std::min(n, k+1); j++) {
            if(i + j <= k) {
                int left = std::max(0, i);
                int right = std::max(0, j);
                int sum = 0;
                for(int l = left; l < n - right; l++) {
                    sum += b[l];
                }
                max_m = std::max(max_m, sum);
            }
        }
    }

    std::cout << max_m << std::endl;

    return 0;
}
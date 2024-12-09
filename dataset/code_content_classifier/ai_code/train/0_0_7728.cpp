#include <iostream>
#include <vector>
#include <algorithm>

int main() {
    int n;
    std::cin >> n;

    std::vector<int> a(n);
    for(int i = 0; i < n; ++i) {
        std::cin >> a[i];
    }

    std::vector<int> prefix(n + 1);
    for(int i = 0; i < n; ++i) {
        prefix[a[i]] = i + 1;
    }

    int ans = n + 1;
    int left = n + 1;
    for(int i = 1; i <= n; ++i) {
        ans = std::min(ans, prefix[i]);
        if(ans < left) {
            std::cout << left << std::endl;
            return 0;
        }
        left = ans;
    }

    std::cout << n + 1 << std::endl;

    return 0;
}
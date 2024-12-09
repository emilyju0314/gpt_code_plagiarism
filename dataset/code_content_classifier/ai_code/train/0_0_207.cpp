#include <iostream>
#include <algorithm>
#include <vector>

int main() {
    int n, k;
    std::cin >> n >> k;

    std::vector<int> A(n);
    for(int i = 0; i < n; i++) {
        std::cin >> A[i];
    }

    std::sort(A.begin(), A.end());

    int ans = 0;
    for(int i = 0; i < min(k, n-k); i++) {
        ans += A[i];
    }

    std::cout << ans << std::endl;

    return 0;
}
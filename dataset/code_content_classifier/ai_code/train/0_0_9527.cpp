#include <iostream>
#include <vector>
#include <algorithm>

int main() {
    int N, M;
    std::cin >> N >> M;
    
    std::vector<int> A(N);
    for (int i = 0; i < N; ++i) {
        std::cin >> A[i];
    }
    
    std::sort(A.begin(), A.end());
    
    int ans = 0;
    for (int i = 0; i < N; i += M) {
        int end = std::min(i + M, N);
        int range = A[end - 1] - A[i];
        ans += range;
    }
    
    std::cout << ans << std::endl;
    
    return 0;
}
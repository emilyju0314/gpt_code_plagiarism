#include <iostream>
#include <vector>
#include <algorithm>

int main() {
    int N;
    std::cin >> N;
    
    std::vector<int> A(N), B(N);
    for (int i = 0; i < N; i++) {
        std::cin >> A[i] >> B[i];
    }
    
    std::vector<int> medians;
    
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            medians.push_back(A[i] + B[j]);
        }
    }
    
    std::sort(medians.begin(), medians.end());
    
    int ans = 0;
    if (N % 2 == 0) {
        ans = medians[N*N/2 - 1 + N] - medians[N*N/2];
    } else {
        ans = medians[N*N/2] - medians[N*N/2];
    }
    
    std::cout << ans << std::endl;
    
    return 0;
}
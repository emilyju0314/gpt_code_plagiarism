#include <iostream>
#include <vector>
#include <algorithm>

int main() {
    int n, m;
    std::cin >> n;
    
    std::vector<int> A(n);
    for (int i = 0; i < n; i++) {
        std::cin >> A[i];
    }
    
    std::cin >> m;
    
    std::vector<int> B(m);
    for (int i = 0; i < m; i++) {
        std::cin >> B[i];
    }
    
    std::sort(A.begin(), A.end());
    std::sort(B.begin(), B.end());
    
    int i = 0, j = 0;
    while (i < n && j < m) {
        if (A[i] == B[j]) {
            j++;
        }
        i++;
    }
    
    if (j == m) {
        std::cout << 1 << std::endl;
    } else {
        std::cout << 0 << std::endl;
    }
    
    return 0;
}
#include <iostream>
#include <vector>

int main() {
    int n;
    std::cin >> n;
    
    std::vector<int> A(n);
    for (int i = 0; i < n; i++) {
        std::cin >> A[i];
    }
    
    int q;
    std::cin >> q;
    
    for (int i = 0; i < q; i++) {
        int b, m, e;
        std::cin >> b >> m >> e;
        
        for (int k = 0; k < (e - b); k++) {
            int start = b + k;
            int end = b + (k + (e - m)) % (e - b);
            std::swap(A[start], A[end]);
        }
    }
    
    for (int i = 0; i < n; i++) {
        std::cout << A[i];
        if (i < n - 1) {
            std::cout << " ";
        }
    }
    
    std::cout << std::endl;
    
    return 0;
}
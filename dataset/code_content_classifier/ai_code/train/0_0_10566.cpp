#include <iostream>
#include <vector>

bool solve(int p, int t, std::vector<int>& A) {
    if (t == 0) {
        return true;
    }
    if (p >= A.size() || t < 0) {
        return false;
    }
    
    return solve(p + 1, t - A[p], A) || solve(p + 1, t, A);
}

int main() {
    int n, q;
    std::cin >> n;
    
    std::vector<int> A(n);
    for (int i = 0; i < n; i++) {
        std::cin >> A[i];
    }
    
    std::cin >> q;
    for (int i = 0; i < q; i++) {
        int M;
        std::cin >> M;
        
        if (solve(0, M, A)) {
            std::cout << "yes" << std::endl;
        } else {
            std::cout << "no" << std::endl;
        }
    }
    
    return 0;
}
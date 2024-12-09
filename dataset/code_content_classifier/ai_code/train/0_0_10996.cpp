#include <iostream>
#include <vector>
#include <algorithm>

int main() {
    int N;
    std::cin >> N;
    
    std::vector<int> A(N);
    for (int i = 0; i < N; i++) {
        std::cin >> A[i];
    }
    
    std::vector<int> B(N);
    for (int i = 0; i < N; i++) {
        std::cin >> B[i];
    }
    
    int Q;
    std::cin >> Q;
    
    for (int i = 0; i < Q; i++) {
        int x, y, z;
        std::cin >> x >> y >> z;
        
        if (x == 1) {
            A[y - 1] = z;
        } else if (x == 2) {
            B[y - 1] = z;
        } else if (x == 3) {
            std::cout << *std::min_element(A.begin() + y - 1, A.begin() + z) << std::endl;
        } else if (x == 4) {
            std::cout << *std::min_element(B.begin() + y - 1, B.begin() + z) << std::endl;
        } else if (x == 5) {
            A = B;
        } else if (x == 6) {
            B = A;
        }
    }
    
    return 0;
}
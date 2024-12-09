#include <iostream>
#include <vector>

int main() {
    int N;
    std::cin >> N;
    
    std::vector<int> B(N);
    for (int i = 0; i < N; i++) {
        std::cin >> B[i];
    }
    
    std::vector<int> A(N);
    for (int i = 0; i < N; i++) {
        A[i] = 0;
    }
    
    for (int i = 0; i < N; i++) {
        for (int j = i + 1; j < N; j++) {
            A[i] += B[j];
            A[j] = B[i] - A[i];
        }
    }
    
    for (int i = 0; i < N; i++) {
        if (A[i] < -1e9 || A[i] > 1e9) {
            std::cout << "NO" << std::endl;
            return 0;
        }
    }
    
    std::cout << "YES" << std::endl;
    for (int i = 0; i < N; i++) {
        std::cout << A[i] << " ";
    }
    
    return 0;
}
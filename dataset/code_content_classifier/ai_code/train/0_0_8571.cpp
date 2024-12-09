#include <iostream>
#include <vector>

int main() {
    int N, M;
    std::cin >> N >> M;
    
    std::vector<int> A(N);
    std::vector<int> B(M);
    
    for(int i = 0; i < N; i++) {
        std::cin >> A[i];
    }
    
    for(int i = 0; i < M; i++) {
        std::cin >> B[i];
    }
    
    long long sum = 0;
    
    for(int i = 0; i < N; i++) {
        for(int j = 0; j < M; j++) {
            sum += A[i] % B[j];
        }
    }
    
    std::cout << sum << std::endl;
    
    return 0;
}
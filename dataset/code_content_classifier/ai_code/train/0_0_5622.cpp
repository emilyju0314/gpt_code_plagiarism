#include <iostream>
#include <vector>

int main() {
    // Input
    int N, a, d, M, K;
    std::cin >> N >> a >> d >> M;
    
    std::vector<int> A(N);
    for(int i = 0; i < N; i++) {
        A[i] = a + i * d;
    }
    
    for(int i = 0; i < M; i++) {
        int x, y, z;
        std::cin >> x >> y >> z;
        y--; z--;
        
        if(x == 0) {
            std::swap(A[y], A[z]);
        } else {
            A[y] = A[z];
        }
    }
    
    std::cin >> K;
    
    std::cout << A[K-1] << std::endl;

    return 0;
}
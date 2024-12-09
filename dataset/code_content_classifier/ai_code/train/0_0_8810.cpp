#include <iostream>
#include <vector>
#include <cmath>

const int MOD = 1e9 + 7;

std::vector<std::vector<int>> matrixMultiply(const std::vector<std::vector<int>>& A, const std::vector<std::vector<int>>& B, int N) {
    std::vector<std::vector<int>> C(N, std::vector<int>(N, 0));
    
    for(int i = 0; i < N; i++) {
        for(int j = 0; j < N; j++) {
            for(int k = 0; k < N; k++) {
                C[i][j] = (C[i][j] + (1LL * A[i][k] * B[k][j]) % MOD) % MOD;
            }
        }
    }
    
    return C;
}

std::vector<std::vector<int>> matrixExponentiation(const std::vector<std::vector<int>>& A, int N, long long K) {
    if(K == 1) {
        return A;
    }
    
    std::vector<std::vector<int>> halfPower = matrixExponentiation(A, N, K / 2);
    std::vector<std::vector<int>> result = matrixMultiply(halfPower, halfPower, N);
    
    if(K % 2 == 1) {
        result = matrixMultiply(result, A, N);
    }
    
    return result;
}

int main() {
    int N, K;
    std::cin >> N >> K;
    
    std::vector<std::vector<int>> adjacencyMatrix(N, std::vector<int>(N));
    for(int i = 0; i < N; i++) {
        for(int j = 0; j < N; j++) {
            std::cin >> adjacencyMatrix[i][j];
        }
    }
    
    std::vector<std::vector<int>> result = matrixExponentiation(adjacencyMatrix, N, K);
    
    int numPaths = 0;
    for(int i = 0; i < N; i++) {
        for(int j = 0; j < N; j++) {
            numPaths = (numPaths + result[i][j]) % MOD;
        }
    }
    
    std::cout << numPaths << std::endl;
    
    return 0;
}
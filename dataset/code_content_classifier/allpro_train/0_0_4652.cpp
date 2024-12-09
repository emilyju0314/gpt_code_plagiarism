#include <iostream>
#include <vector>
#include <algorithm>

int main() {
    int N;
    std::cin >> N;
    
    std::vector<int> A(N);
    std::vector<int> B(N);
    
    for(int i = 0; i < N; i++) {
        std::cin >> A[i];
    }
    
    for(int i = 0; i < N; i++) {
        std::cin >> B[i];
    }
    
    int operations = 0;
    bool possible = true;
    
    while(true) {
        bool sorted = true;
        for(int i = 0; i < N - 1; i++) {
            if(A[i] > A[i + 1] && B[i] > B[i + 1]) {
                std::swap(A[i], A[i + 1]);
                std::swap(B[i], B[i + 1]);
                operations++;
                sorted = false;
            }
        }
        
        if(sorted) {
            break;
        }
    }
    
    for(int i = 0; i < N - 1; i++) {
        if(A[i] > A[i + 1] || B[i] > B[i + 1]) {
            possible = false;
            break;
        }
    }
    
    if(possible) {
        std::cout << operations << std::endl;
    } else {
        std::cout << -1 << std::endl;
    }
    
    return 0;
}
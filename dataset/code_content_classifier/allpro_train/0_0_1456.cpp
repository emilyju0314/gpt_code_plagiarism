#include <iostream>
#include <vector>

int main() {
    int N;
    std::cin >> N;
    
    std::vector<long long> A(N);
    for (int i = 0; i < N; i++) {
        std::cin >> A[i];
    }
    
    int count = 0;
    long long prev = A[N-1];
    for (int i = N-2; i >= 0; i--) {
        while (A[i] < prev) {
            A[i] *= -2;
            count++;
        }
        prev = A[i];
    }
    
    bool possible = true;
    for (int i = 0; i < N-1; i++) {
        if (A[i] > A[i+1]) {
            possible = false;
            break;
        }
    }
    
    if (possible) {
        std::cout << count << std::endl;
    } else {
        std::cout << "-1" << std::endl;
    }
    
    return 0;
}
#include <iostream>
#include <vector>
#include <algorithm>

int main() {
    int N;
    std::cin >> N;
    
    std::vector<int> X(N);
    for (int i = 0; i < N; i++) {
        std::cin >> X[i];
    }
    
    std::sort(X.begin(), X.end());
    
    int median;
    if (N % 2 == 0) {
        median = (X[N/2 - 1] + X[N/2]) / 2;
    } else {
        median = X[N/2];
    }
    
    for (int i = 0; i < N; i++) {
        if (X[i] < median) {
            std::cout << X[N/2] << std::endl;
        } else {
            std::cout << X[N/2 - 1] << std::endl;
        }
    }
    
    return 0;
}
#include <iostream>
#include <vector>

void CountingSort(std::vector<int>& A, std::vector<int>& B, int k) {
    std::vector<int> C(k+1, 0);
    
    for(int j = 0; j < A.size(); j++) {
        C[A[j]]++;
    }
    
    for(int i = 1; i <= k; i++) {
        C[i] += C[i-1];
    }
    
    for(int j = A.size()-1; j >= 0; j--) {
        B[C[A[j]]-1] = A[j];
        C[A[j]]--;
    }
}

int main() {
    int n;
    std::cin >> n;
    
    std::vector<int> A(n);
    for(int i = 0; i < n; i++) {
        std::cin >> A[i];
    }
    
    int k = 10000;
    std::vector<int> B(n);
    
    CountingSort(A, B, k);
    
    for(int i = 0; i < n; i++) {
        std::cout << B[i] << " ";
    }
    
    return 0;
}
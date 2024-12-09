#include <iostream>
#include <vector>
#include <unordered_set>

int main() {
    int N;
    std::cin >> N;
    
    std::vector<int> A(N);
    for(int i = 0; i < N; i++) {
        std::cin >> A[i];
    }
    
    int count = 0;
    std::unordered_set<int> divisors;
    
    for(int i = 0; i < N; i++) {
        bool flag = true;
        
        for(int j = 0; j < N; j++) {
            if(i != j && A[j] % A[i] == 0) {
                flag = false;
                divisors.insert(A[j]);
            }
        }
        
        if(flag) {
            count++;
        }
    }
    
    std::cout << count << std::endl;
    
    return 0;
}
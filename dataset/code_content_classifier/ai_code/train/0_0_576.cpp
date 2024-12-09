#include <iostream>
#include <vector>
#include <unordered_map>

int main() {
    int N;
    std::cin >> N;
    
    std::vector<int> A(N);
    for(int i = 0; i < N; i++) {
        std::cin >> A[i];
    }
    
    int Q;
    std::cin >> Q;
    
    std::unordered_map<int, int> replacement;
    for(int i = 0; i < Q; i++) {
        int B, C;
        std::cin >> B >> C;
        replacement[B] = C;
        
        long long sum = 0;
        for(int j = 0; j < N; j++) {
            if(A[j] == B) {
                A[j] = C;
            }
            sum += A[j];
        }
        std::cout << sum << std::endl;
    }
    
    return 0;
}
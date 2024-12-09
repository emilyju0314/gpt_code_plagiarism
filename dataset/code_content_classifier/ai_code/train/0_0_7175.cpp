#include <iostream>
#include <vector>
#include <algorithm>

int main() {
    int N;
    std::cin >> N;
    
    std::vector<int> pieces(N);
    for(int i = 0; i < N; i++) {
        std::cin >> pieces[i];
    }
    
    std::vector<int> prefix(N+1, 0);
    for(int i = 1; i <= N; i++) {
        prefix[i] = prefix[i-1] + pieces[i-1];
    }
    
    int total = 0;
    for(int i = 1; i <= N; i++) {
        int sum = prefix[N] - prefix[i] + prefix[i-1] - prefix[0];
        
        if((N-i) % 2 == 0) {
            total = std::max(total, sum);
        }
    }
    
    std::cout << total << std::endl;
    
    return 0;
}
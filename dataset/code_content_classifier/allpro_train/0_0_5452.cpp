#include <iostream>
#include <vector>

int main() {
    int N;
    std::cin >> N;
    
    std::vector<int> p(N);
    for(int i = 0; i < N; i++) {
        std::cin >> p[i];
    }
    
    int Q;
    std::cin >> Q;
    
    for(int i = 0; i < Q; i++) {
        int l, r;
        std::cin >> l >> r;
        
        int count = 0;
        for(int j = l-1; j < r-1; j++) {
            for(int k = j+1; k < r; k++) {
                if(p[j] > p[k]) {
                    count++;
                }
            }
        }
        
        std::cout << count << std::endl;
    }
    
    return 0;
}
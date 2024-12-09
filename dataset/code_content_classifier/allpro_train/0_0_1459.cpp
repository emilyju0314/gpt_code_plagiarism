#include <iostream>
#include <cmath>

int main() {
    int N, A, B, C, D;
    std::cin >> N >> A >> B >> C >> D;
    
    int max_diff = D - C;
    int min_diff = C - D;
    
    int diff1 = abs(A - B);
    int diff2 = abs(A - B);
    
    for(int i = 3; i <= N; i++) {
        if(A + (i-1)*min_diff <= B + (i-1)*max_diff || A + (i-1)*max_diff >= B + (i-1)*min_diff) {
            std::cout << "YES" << std::endl;
            return 0;
        }
    }
    
    std::cout << "NO" << std::endl;
    
    return 0;
}
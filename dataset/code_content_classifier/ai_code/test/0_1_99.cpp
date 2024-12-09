#include <iostream>

long long calculateFinalPosition(long long x0, long long n) {
    long long currPos = x0;
    bool isJumpToLeft = (currPos % 2 == 0);
    
    for (long long i = 1; i <= n; i++) {
        if (isJumpToLeft) {
            currPos -= i;
        } else {
            currPos += i;
        }
        isJumpToLeft = !isJumpToLeft;
    }
    
    return currPos;
}

int main() {
    int t;
    std::cin >> t;
    
    for (int i = 0; i < t; i++) {
        long long x0, n;
        std::cin >> x0 >> n;
        
        long long finalPos = calculateFinalPosition(x0, n);
        std::cout << finalPos << std::endl;
    }
    
    return 0;
}
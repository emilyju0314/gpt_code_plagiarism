#include <iostream>

long long calculateFinalPosition(long long x0, long long n) {
    long long targetCoordinate = 0;
    long long remainingJumps = n;
    
    while (remainingJumps > 0) {
        long long currentJump = targetCoordinate % 2 == 0 ? remainingJumps : remainingJumps + 1;
        
        if (targetCoordinate % 2 == 0) {
            targetCoordinate -= currentJump;
        } else {
            targetCoordinate += currentJump;
        }
        
        remainingJumps -= currentJump;
    }
    
    return x0 + targetCoordinate;
}

int main() {
    int t;
    std::cin >> t;
    
    for (int i = 0; i < t; i++) {
        long long x0, n;
        std::cin >> x0 >> n;
        
        long long finalPosition = calculateFinalPosition(x0, n);
        std::cout << finalPosition << std::endl;
    }
    
    return 0;
}
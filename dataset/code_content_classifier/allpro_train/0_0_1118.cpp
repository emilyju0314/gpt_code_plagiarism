#include <iostream>
#include <vector>

int main() {
    int N;
    std::cin >> N;
    
    std::vector<int> hand(N);
    std::vector<int> frustration(N);
    
    for (int i = 0; i < N; i++) {
        std::cin >> hand[i];
    }
    
    for (int i = 0; i < N; i++) {
        std::cin >> frustration[i];
    }
    
    int minTotalFrustration = 100000; // Initialize to a large value
    
    for (int i = 0; i < N; i++) {
        int totalFrustration = 0;
        
        for (int j = 0; j < N; j++) {
            if (hand[j] == 0) { // Right handed sage
                if (hand[(j+1)%N] == 1) { // Check right neighbor
                    totalFrustration += frustration[j];
                }
            } else { // Left handed sage
                if (hand[(j+N-1)%N] == 0) { // Check left neighbor
                    totalFrustration += frustration[j];
                }
            }
        }
        
        if (totalFrustration < minTotalFrustration) {
            minTotalFrustration = totalFrustration;
        }
        
        // Rotate the hand array to try different arrangements
        std::rotate(hand.begin(), hand.begin() + 1, hand.end());
    }
    
    std::cout << minTotalFrustration << std::endl;
    
    return 0;
}
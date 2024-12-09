#include <iostream>
#include <vector>
#include <cmath>

int main() {
    int K, N, Q;
    std::cin >> K >> N >> Q;

    std::vector<int> cards(N);
    for(int i = 0; i < N; i++) {
        std::cin >> cards[i];
    }

    int swapL, swapR;
    for(int i = 0; i < Q; i++) {
        std::cin >> swapL >> swapR;

        int disc = 1;
        for(int j = 0; j < N; j++) {
            if(j == swapL - 1) {
                disc = std::abs(cards[swapR-1]) >= K ? disc + K - 1 : disc + std::abs(cards[swapR-1]);
            } else if(j == swapR - 1) {
                disc = std::abs(cards[swapL-1]) >= K ? disc + K - 1 : disc + std::abs(cards[swapL-1]);
            } else {
                disc += cards[j] >= 0 ? cards[j] : K + cards[j];
            }
            disc = (disc % K + K) % K;
        }

        if(disc == 0) {
            disc = K;
        }
        
        std::cout << (disc == 0 ? K : disc) << std::endl;
    }
    
    return 0;
}
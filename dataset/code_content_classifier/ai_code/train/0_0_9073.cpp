#include <iostream>
#include <vector>

std::string winner(int N, std::vector<std::pair<int, int>>& piles) {
    long long takahashi = 0, aoki = 0;
    
    for(int i = 0; i < N; i++) {
        int stones = piles[i].first;
        int divisor = piles[i].second;
        
        long long max_stones = std::min((long long)stones, (long long)(stones / divisor));
        
        if(i % 2 == 0) {
            takahashi += max_stones;
        } else {
            aoki += max_stones;
        }
    }
    
    if(takahashi > aoki) {
        return "Takahashi";
    } else {
        return "Aoki";
    }
}

int main() {
    int N;
    std::cin >> N;
    
    std::vector<std::pair<int, int>> piles(N);
    for(int i = 0; i < N; i++) {
        int stones, divisor;
        std::cin >> stones >> divisor;
        piles[i] = std::make_pair(stones, divisor);
    }
    
    std::cout << winner(N, piles) << std::endl;
    
    return 0;
}
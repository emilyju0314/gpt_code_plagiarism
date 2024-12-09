#include <iostream>
#include <vector>
#include <algorithm>

int main() {
    int N, M;
    std::cin >> N >> M;
    
    std::vector<int> votes(N);
    for (int i = 0; i < N; i++) {
        std::cin >> votes[i];
    }
    
    std::sort(votes.begin(), votes.end(), std::greater<int>());
    
    int totalVotes = 0;
    for (int i = 0; i < N; i++) {
        if (i < M) {
            totalVotes += votes[i];
        } else {
            if (votes[i] * 4 >= totalVotes) {
                std::cout << "No" << std::endl;
                return 0;
            }
        }
    }
    
    std::cout << "Yes" << std::endl;
    
    return 0;
}
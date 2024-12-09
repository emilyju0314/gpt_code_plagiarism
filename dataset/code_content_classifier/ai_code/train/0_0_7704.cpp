#include <iostream>
#include <vector>

int main() {
    int N, M;
    std::cin >> N;
    
    std::vector<int> score(N);
    for(int i=0; i<N; i++) {
        std::cin >> score[i];
    }
    
    std::cin >> M;
    
    std::vector<int> ability(M);
    for(int i=0; i<M; i++) {
        std::cin >> ability[i];
    }
    
    std::vector<int> target(M);
    for(int i=0; i<M; i++) {
        std::cin >> target[i];
    }
    
    int maxScore = 0;
    
    for(int i=0; i<N; i++) {
        maxScore += score[i];
    }
    
    for(int i=0; i<M; i++) {
        int currentScore = 0;
        
        for(int j=0; j<N; j++) {
            if(score[j] <= ability[i]) {
                currentScore += score[j];
            }
        }
        
        if(currentScore > target[i] && currentScore <= maxScore) {
            std::cout << "Yes" << std::endl;
        } else {
            std::cout << "No" << std::endl;
        }
    }
    
    return 0;
}
#include <iostream>
#include <unordered_set>
#include <vector>

int main() {
    int N, M;
    std::cin >> N;
    
    std::unordered_set<int> candidates;
    for(int i = 0; i < N; i++) {
        int D_i;
        std::cin >> D_i;
        candidates.insert(D_i);
    }
    
    std::cin >> M;
    
    std::vector<int> problems(M);
    for(int i = 0; i < M; i++) {
        std::cin >> problems[i];
    }
    
    bool canCompleteSet = true;
    for(int problem : problems) {
        if(candidates.count(problem) == 0) {
            canCompleteSet = false;
            break;
        }
    }
    
    if(canCompleteSet) {
        std::cout << "YES" << std::endl;
    } else {
        std::cout << "NO" << std::endl;
    }
    
    return 0;
}
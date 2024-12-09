#include <iostream>
#include <vector>
#include <algorithm>

int main() {
    int N;
    std::cin >> N;
    
    std::vector<std::pair<int, int>> weights(N);
    for(int i = 0; i < N; i++) {
        std::cin >> weights[i].first;
        weights[i].second = i;
    }
    
    std::sort(weights.begin(), weights.end());
    
    std::string direction;
    std::cin >> direction;
    
    std::vector<std::pair<int, char>> result(N);
    result[weights[0].second] = {weights[0].first, (direction[0] == 'L' ? 'L' : 'R')};
    
    int heavier = 0, lighter = 0;
    for(int i = 1; i < N; i++) {
        if(direction[i] == 'L') {
            result[weights[i].second] = {weights[i].first, (result[weights[i-1].second].second == 'L' ? 'R' : 'L')};
        } else {
            result[weights[i].second] = {weights[i].first, (result[weights[i-1].second].second == 'R' ? 'R' : 'L')};
        }
        
        if(result[weights[i].second].second == 'L') {
            heavier++;
        } else {
            lighter++;
        }
    }
    
    if(heavier != lighter) {
        std::cout << "-1" << std::endl;
    } else {
        for(int i = 0; i < N; i++) {
            std::cout << result[i].first << " " << result[i].second << std::endl;
        }
    }
    
    return 0;
}
#include <iostream>
#include <vector>

int main() {
    int N;
    std::cin >> N;

    std::vector<int> heights(N);
    for(int i = 0; i < N; i++) {
        std::cin >> heights[i];
    }

    int maxMoves = 0, currentMoves = 0;
    for(int i = 0; i < N - 1; i++) {
        if(heights[i] >= heights[i + 1]) {
            currentMoves++;
        } else {
            maxMoves = std::max(maxMoves, currentMoves);
            currentMoves = 0;
        }
    }

    maxMoves = std::max(maxMoves, currentMoves);
    
    std::cout << maxMoves << std::endl;

    return 0;
}
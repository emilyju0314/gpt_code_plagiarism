#include <iostream>
#include <vector>
#include <string>

bool isPossibleBigMaze(int N, int M, std::vector<std::vector<std::string>> mazes) {
    for (int i = 0; i < M; i++) {
        for (int j = 0; j < N - 1; j++) {
            if (mazes[i][j][N-1] == '.') {
                return true;
            }
        }
    }
    return false;
}

int main() {
    int N, M;
    
    while (true) {
        std::cin >> N >> M;
        if (N == 0 && M == 0) {
            break;
        }
        
        std::vector<std::vector<std::string>> mazes(M, std::vector<std::string>(N));
        
        for (int i = 0; i < M; i++) {
            for (int j = 0; j < N; j++) {
                std::cin >> mazes[i][j];
            }
        }
        
        if (isPossibleBigMaze(N, M, mazes)) {
            std::cout << "Yes" << std::endl;
        } else {
            std::cout << "No" << std::endl;
        }
    }
    
    return 0;
}
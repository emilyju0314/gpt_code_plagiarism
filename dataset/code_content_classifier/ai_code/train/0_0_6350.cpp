#include <iostream>
#include <vector>
#include <cmath>

int main() {
    int n, m, d;
    std::cin >> n >> m >> d;

    std::vector<std::vector<int>> matrix(n, std::vector<int>(m));
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            std::cin >> matrix[i][j];
        }
    }

    int minMoves = INT_MAX;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            bool possible = true;
            int moves = 0;
            int reference = matrix[i][j];
            for(int k = 0; k < n; k++) {
                for(int l = 0; l < m; l++) {
                    if((std::abs(matrix[k][l] - reference) % d) != 0) {
                        possible = false;
                        break;
                    }
                    moves += std::abs(matrix[k][l] - reference) / d;
                }
                if(!possible) {
                    break;
                }
            }

            if(possible && moves < minMoves) {
                minMoves = moves;
            }
        }
    }

    if(minMoves == INT_MAX) {
        std::cout << "-1" << std::endl;
    } else {
        std::cout << minMoves << std::endl;
    }

    return 0;
}
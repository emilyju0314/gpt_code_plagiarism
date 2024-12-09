#include <iostream>
#include <vector>

int main() {
    int testCase = 1;
    
    while(true) {
        int N;
        std::cin >> N;
        
        if(N == 0) {
            break;
        }
        
        std::cout << "Case " << testCase << ":" << std::endl;
        
        std::vector<std::vector<int>> matrix(N, std::vector<int>(N));
        
        int x = 0, y = 0, num = 1;
        matrix[x][y] = num++;
        
        while(num <= N * N) {
            if(x - 1 >= 0 && y + 1 < N && matrix[x-1][y+1] == 0) {
                while(x - 1 >= 0 && y + 1 < N && matrix[x-1][y+1] == 0) {
                    matrix[--x][++y] = num++;
                }
            } else if(y + 1 < N && matrix[x][y + 1] == 0) {
                while(y + 1 < N && matrix[x][y+1] == 0) {
                    matrix[x][++y] = num++;
                }
            } else if(x + 1 < N && matrix[x + 1][y] == 0) {
                while(x + 1 < N && matrix[x + 1][y] == 0) {
                    matrix[++x][y] = num++;
                }
            } else {
                while(y - 1 >= 0 && x + 1 < N && matrix[x+1][y-1] == 0) {
                    matrix[++x][--y] = num++;
                }
            }
        }
        
        for(int i = 0; i < N; i++) {
            for(int j = 0; j < N; j++) {
                std::cout << std::right << std::setw(3) << matrix[i][j];
            }
            std::cout << std::endl;
        }
        
        testCase++;
    }
    
    return 0;
}
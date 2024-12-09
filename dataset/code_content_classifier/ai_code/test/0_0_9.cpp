#include <iostream>
#include <vector>

int main() {
    int n, m, k;
    std::cin >> n >> m >> k;
    
    std::vector<std::vector<int>> grid(n, std::vector<int>(m));
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            std::cin >> grid[i][j];
        }
    }
    
    std::vector<int> columns(k);
    for(int i = 0; i < k; i++) {
        std::cin >> columns[i];
    }
    
    std::vector<int> result(k);
    for(int i = 0; i < k; i++) {
        int col = columns[i];
        int row = 0;
        while(row < n) {
            if(grid[row][col-1] == 1) {
                col++;
            } else if(grid[row][col-1] == 2) {
                row++;
            } else if(grid[row][col-1] == 3) {
                col--;
            }
            grid[row][col-1] = 2;
        }
        result[i] = col;
    }
    
    for(int i = 0; i < k; i++) {
        std::cout << result[i] << " ";
    }
    
    return 0;
}
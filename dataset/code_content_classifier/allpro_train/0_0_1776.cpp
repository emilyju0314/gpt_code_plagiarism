#include <iostream>
#include <vector>
#include <string>

bool canWinGame(int n, int k, std::vector<std::string>& field) {
    // Find the position of Philip (marked as 's')
    int row = 0;
    int col = 0;
    for(int i = 0; i < 3; i++) {
        for(int j = 0; j < n; j++) {
            if(field[i][j] == 's') {
                row = i;
                col = j;
            }
        }
    }

    // Move Philip to the rightmost column
    while(col < n-1) {
        // Check if Philip is blocked by any train
        if(row > 0 && field[row-1][col+1] != '.') {
            row--;
        } else if(row < 2 && field[row+1][col+1] != '.') {
            row++;
        }
        col++;
        
        // Check if Philip is in the same cell as any train
        if(field[row][col] != '.') {
            return false;
        }
    }

    return true;
}

int main() {
    int t;
    std::cin >> t;

    while(t--) {
        int n, k;
        std::cin >> n >> k;

        std::vector<std::string> field;
        for(int i = 0; i < 3; i++) {
            std::string row;
            std::cin >> row;
            field.push_back(row);
        }

        if(canWinGame(n, k, field)) {
            std::cout << "YES" << std::endl;
        } else {
            std::cout << "NO" << std::endl;
        }
    }

    return 0;
}
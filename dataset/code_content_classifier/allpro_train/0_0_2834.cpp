#include <iostream>
#include <vector>

int main() {
    std::vector<std::vector<int>> grid(3, std::vector<int>(3));

    // Read input values into the grid
    for(int i = 0; i < 3; i++) {
        for(int j = 0; j < 3; j++) {
            std::cin >> grid[i][j];
        }
    }

    bool isCorrect = true;

    // Check if the values can be formed by adding one element from the row and one element from the column
    for(int i = 0; i < 3; i++) {
        for(int j = 0; j < 3; j++) {
            bool found = false;
            for(int k = 0; k < 3; k++) {
                for(int l = 0; l < 3; l++) {
                    if(grid[i][j] == grid[i][k] + grid[l][j]) {
                        found = true;
                        break;
                    }
                }
                if(found) break;
            }
            if(!found) {
                isCorrect = false;
                break;
            }
        }
        if(!isCorrect) break;
    }

    // Output the result
    if(isCorrect) {
        std::cout << "Yes" << std::endl;
    } else {
        std::cout << "No" << std::endl;
    }

    return 0;
}
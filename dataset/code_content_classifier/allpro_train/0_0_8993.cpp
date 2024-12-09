#include <iostream>
#include <vector>

int main() {
    int n;
    
    while (std::cin >> n) {
        if (n == 0) {
            break;
        }
        
        std::vector<std::vector<int>> students(n, std::vector<int>(n));
        
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                std::cin >> students[i][j];
            }
        }
        
        int tallest_in_column, shortest_in_row;
        
        for (int i = 0; i < n; i++) {
            shortest_in_row = students[i][0];
            for (int j = 1; j < n; j++) {
                if (students[i][j] < shortest_in_row) {
                    shortest_in_row = students[i][j];
                }
            }
            
            for (int j = 0; j < n; j++) {
                tallest_in_column = students[0][j];
                for (int k = 1; k < n; k++) {
                    if (students[k][j] > tallest_in_column) {
                        tallest_in_column = students[k][j];
                    }
                }
                
                if (shortest_in_row == tallest_in_column) {
                    std::cout << shortest_in_row << std::endl;
                    break;
                }
            }
        }
    }
    
    return 0;
}
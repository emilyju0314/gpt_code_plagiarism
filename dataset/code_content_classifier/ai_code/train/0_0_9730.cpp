#include <iostream>
#include <vector>

int main() {
    int n;
    std::cin >> n;
    
    std::vector<std::vector<int>> matrix(n, std::vector<int>(n));
    
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            std::cin >> matrix[i][j];
        }
    }
    
    int sum = 0;
    
    // Elements of the main diagonal
    for(int i = 0; i < n; i++) {
        sum += matrix[i][i];
    }
    
    // Elements of the secondary diagonal
    for(int i = 0; i < n; i++) {
        sum += matrix[i][n - i - 1];
    }
    
    // Elements of the middle row
    int middleRow = n / 2;
    for(int i = 0; i < n; i++) {
        sum += matrix[middleRow][i];
    }
    
    // Elements of the middle column
    int middleCol = n / 2;
    for(int i = 0; i < n; i++) {
        sum += matrix[i][middleCol];
    }
    
    // Subtract the duplicate elements
    sum -= 3 * matrix[middleRow][middleCol];
    
    std::cout << sum << std::endl;
    
    return 0;
}
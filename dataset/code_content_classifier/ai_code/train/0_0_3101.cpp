#include <iostream>
#include <vector>
#include <algorithm>

int main() {
    int n;
    std::cin >> n;

    std::vector<std::vector<int>> matrix(n, std::vector<int>(n));

    // Input matrix
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            std::cin >> matrix[i][j];
        }
    }

    // Calculate maximum sum in horizontal direction
    int max_horizontal = 0;

    for(int i = 0; i < n; i++) {
        int sum = 0;
        for(int j = 0; j < n; j++) {
            sum += matrix[i][j];
            max_horizontal = std::max(max_horizontal, sum);
            if(sum < 0) {
                sum = 0;
            }
        }
    }

    // Calculate maximum sum in vertical direction
    int max_vertical = 0;

    for(int j = 0; j < n; j++) {
        int sum = 0;
        for(int i = 0; i < n; i++) {
            sum += matrix[i][j];
            max_vertical = std::max(max_vertical, sum);
            if(sum < 0) {
                sum = 0;
            }
        }
    }

    // Print the maximum value in either direction
    std::cout << std::max(max_horizontal, max_vertical) << std::endl;

    return 0;
}
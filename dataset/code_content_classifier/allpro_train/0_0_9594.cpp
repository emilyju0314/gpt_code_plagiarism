#include <iostream>
#include <vector>
#include <cmath>

int main() {
    int H, W;
    std::cin >> H >> W;
    
    std::vector<std::vector<int>> A(H, std::vector<int>(W));
    std::vector<std::vector<int>> B(H, std::vector<int>(W));
    
    for (int i = 0; i < H; i++) {
        for (int j = 0; j < W; j++) {
            std::cin >> A[i][j];
        }
    }
    
    for (int i = 0; i < H; i++) {
        for (int j = 0; j < W; j++) {
            std::cin >> B[i][j];
        }
    }
    
    // Initialize minimum unbalancedness with a large value
    int min_unbalancedness = INT_MAX;
    
    for (int i = 0; i < H; i++) {
        for (int j = 0; j < W; j++) {
            // Calculate the sum of red and blue numbers
            int red_sum = A[0][0];
            int blue_sum = B[0][0];
            
            // Paint the current square (i, j) with red
            red_sum += A[i][j];
            blue_sum += B[i][j];
            
            // Paint the rest of the grid appropriately
            for (int k = i+1; k < H; k++) {
                red_sum += A[k][j];
                blue_sum += B[k][j];
            }
            for (int k = j+1; k < W; k++) {
                red_sum += A[i][k];
                blue_sum += B[i][k];
            }
            
            // Update the minimum unbalancedness
            min_unbalancedness = std::min(min_unbalancedness, abs(red_sum - blue_sum));
        }
    }
    
    std::cout << min_unbalancedness << std::endl;
    
    return 0;
}
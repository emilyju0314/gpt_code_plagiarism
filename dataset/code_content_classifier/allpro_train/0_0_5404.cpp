#include <iostream>
#include <vector>

int main() {
    int n;
    std::cin >> n;

    // Read the initial matrix A
    std::vector<std::vector<int>> matrix(n, std::vector<int>(n));
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            std::cin >> matrix[i][j];
        }
    }

    int q;
    std::cin >> q;

    // Initialize the variables to keep track of row and column flips
    std::vector<int> row_flips(n, 0);
    std::vector<int> col_flips(n, 0);

    // Initialize the variable to store the unusual square of A
    int unusual_square = 0;

    // Process the queries
    for (int i = 0; i < q; ++i) {
        int query_type, index;
        std::cin >> query_type >> index;
        
        if (query_type == 1) {
            // Flip all values in the i-th row
            row_flips[index - 1] ^= 1;
            unusual_square += (row_flips[index - 1] == 0) ? -1 : 1;
        } else if (query_type == 2) {
            // Flip all values in the i-th column
            col_flips[index - 1] ^= 1;
            unusual_square += (col_flips[index - 1] == 0) ? -1 : 1;
        } else {
            // Output the current unusual square value
            std::cout << (unusual_square % 2);
        }
    }

    std::cout << std::endl;

    return 0;
}
#include <iostream>
#include <vector>
#include <string>

int main() {
    std::vector<std::string> rows(6);

    // Read input
    for (int i = 0; i < 6; i++) {
        std::cin >> rows[i];
    }

    // Find the row with the most vacant places
    int max_empty = 0;
    int row_to_fill = 0;

    for (int i = 0; i < 6; i++) {
        int empty_count = 0;
        for (char c : rows[i]) {
            if (c == '.') {
                empty_count++;
            }
        }
        if (empty_count > max_empty) {
            max_empty = empty_count;
            row_to_fill = i;
        }
    }

    // Find the aisle with the most convenient place
    int aisle_to_fill = 0;

    for (int j = 2; j < 6; j += 2) {
        if (rows[row_to_fill][j] == '.') {
            aisle_to_fill = j;
            break;
        }
    }

    // Fill the most convenient place with 'P'
    rows[row_to_fill][aisle_to_fill] = 'P';

    // Print the updated plan
    for (const std::string& row : rows) {
        std::cout << row << std::endl;
    }

    return 0;
}
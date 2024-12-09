#include <iostream>
#include <vector>

using namespace std;

int ask(int x1, int y1, int x2, int y2) {
    cout << "? " << x1 << " " << y1 << " " << x2 << " " << y2 << endl;
    cout << flush;
    int response;
    cin >> response;
    return response;
}

int main() {
    int n;
    cin >> n;

    vector<vector<int>> grid(n, vector<int>(n));

    // Function to count number of cells in the rectangle
    auto count_cells = [&](int x1, int y1, int x2, int y2) -> int {
        int count = 0;
        for (int i = x1; i <= x2; i++) {
            for (int j = y1; j <= y2; j++) {
                count += grid[i][j];
            }
        }
        return count;
    };

    // Function to check if the rectangle is valid
    auto check_rectangle = [&](int x1, int y1, int x2, int y2) -> bool {
        return count_cells(x1, y1, x2, y2) == 0;
    };

    // Finding the first rectangle
    int x1_1 = 0, y1_1 = 0, x2_1 = 0, y2_1 = 0;
    for (int i = 0; i < n; i++) {
        if (ask(0, 0, i, n - 1) == 1) {
            x2_1 = i;
        }
    }
    for (int j = 0; j < n; j++) {
        if (ask(0, 0, n - 1, j) == 1) {
            y2_1 = j;
        }
    }

    for (int i = 0; i <= x2_1; i++) {
        for (int j = 0; j <= y2_1; j++) {
            grid[i][j] = 1;
        }
    }

    // Finding the second rectangle
    int x1_2 = 0, y1_2 = 0, x2_2 = 0, y2_2 = 0;
    for (int i = x2_1 + 1; i < n; i++) {
        if (ask(x2_1 + 1, 0, i, n - 1) == 1) {
            x2_2 = i;
        }
    }
    for (int j = y2_1 + 1; j < n; j++) {
        if (ask(0, y2_1 + 1, n - 1, j) == 1) {
            y2_2 = j;
        }
    }

    for (int i = x2_1 + 1; i <= x2_2; i++) {
        for (int j = y2_1 + 1; j <= y2_2; j++) {
            grid[i][j] = 2;
        }
    }

    // Printing the result
    cout << "! " << x1_1 + 1 << " " << y1_1 + 1 << " " << x2_1 + 1 << " " << y2_1 + 1 << " "
                 << x1_2 + 1 << " " << y1_2 + 1 << " " << x2_2 + 1 << " " << y2_2 + 1 << endl;
    cout << flush;

    return 0;
}
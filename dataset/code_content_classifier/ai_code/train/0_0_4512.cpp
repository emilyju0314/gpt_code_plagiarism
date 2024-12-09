#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n;
    cin >> n;

    vector<vector<int>> grid(n, vector<int>(n));
    vector<vector<int>> processed(n, vector<int>(n));

    // First cell is 1
    grid[0][0] = 1;
    processed[0][0] = 1;

    for (int i = 1; i < n; i++) {
        cout << "? 1 1 " << i+1 << " " << i+1 << endl;
        cout.flush();
        int res;
        cin >> res;
        if (res == 1) {
            grid[0][i] = 1;
            grid[i][0] = 1;
            processed[0][i] = 1;
            processed[i][0] = 1;
        } else {
            grid[0][i] = 0;
            grid[i][0] = 0;
        }
    }

    for (int i = 1; i < n; i++) {
        for (int j = 1; j < n; j++) {
            if (processed[i][j] == 0) {
                cout << "? 1 " << j+1 << " " << i+1 << " " << j+1 << endl;
                cout.flush();
                int res;
                cin >> res;
                if (res == 1) {
                    grid[i][j] = grid[i-1][j];
                } else {
                    grid[i][j] = 1 - grid[i-1][j];
                }
                processed[i][j] = 1;
            }
        }
    }

    cout << "!" << endl;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << grid[i][j];
        }
        cout << endl;
    }

    return 0;
}
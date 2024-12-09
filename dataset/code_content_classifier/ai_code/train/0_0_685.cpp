#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main() {
    int n, m;
    cin >> n >> m;

    vector<string> grid(n);
    for (int i = 0; i < n; i++) {
        cin >> grid[i];
    }

    // Check if the second person can win
    bool secondPlayerWins = false;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (grid[i][j] == '.') {
                secondPlayerWins = true;
            }
        }
    }

    if (secondPlayerWins) {
        cout << "Second" << endl;
    } else {
        cout << "First" << endl;
    }

    return 0;
}
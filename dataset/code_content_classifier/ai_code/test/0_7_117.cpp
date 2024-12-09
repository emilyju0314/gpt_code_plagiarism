#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main() {
    int t;
    cin >> t;

    while (t--) {
        int n, m;
        cin >> n >> m;

        vector<string> grid(n);
        for (int i = 0; i < n; i++) {
            cin >> grid[i];
        }

        pair<int, int> lab;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid[i][j] == 'L') {
                    lab.first = i;
                    lab.second = j;
                }
            }
        }

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid[i][j] == '.') {
                    if ((i == lab.first && (j == lab.second - 1 || j == lab.second + 1)) ||
                        (j == lab.second && (i == lab.first - 1 || i == lab.first + 1))) {
                        grid[i][j] = '+';
                    }
                }
            }
        }

        for (int i = 0; i < n; i++) {
            cout << grid[i] << endl;
        }
    }

    return 0;
}
#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>

using namespace std;

int main() {
    int t;
    cin >> t;

    while (t--) {
        int n, m;
        cin >> n >> m;

        vector<vector<int>> matrix(n, vector<int>(m));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> matrix[i][j];
            }
        }

        vector<char> colors(n);
        bool red_found = false, blue_found = false;
        for (int i = 0; i < n; i++) {
            for (int j = 1; j < m; j++) {
                if (matrix[i][j] != matrix[i][0]) {
                    if (!red_found) {
                        colors[i] = 'R';
                        red_found = true;
                    } else if (!blue_found) {
                        colors[i] = 'B';
                        blue_found = true;
                    }
                    break;
                }
            }
        }

        if (!red_found || !blue_found) {
            cout << "NO" << endl;
            continue;
        }

        cout << "YES" << endl;
        for (char color : colors) {
            cout << color;
        }
        cout << endl;

        int k = 0;
        while (k < m && matrix[0][k] == matrix[0][0]) {
            k++;
        }
        cout << k << endl;
    }

    return 0;
}
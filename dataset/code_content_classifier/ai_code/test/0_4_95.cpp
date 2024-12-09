#include <iostream>
#include <vector>
#include <algorithm>

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
        bool perfect = false;

        for (int i = 0; i < n; i++) {
            if (perfect) break;

            bool hasRed = false, hasBlue = false;
            for (int j = 0; j < m; j++) {
                if (j+1 < m && matrix[i][j] < matrix[i][j+1]) {
                    hasRed = true;
                } else {
                    hasBlue = true;
                }
            }

            if (hasRed && hasBlue) {
                perfect = true;
                for (int j = 0; j < m; j++) {
                    if (matrix[i][j] < matrix[i][j+1]) {
                        colors[i] = 'R';
                    } else {
                        colors[i] = 'B';
                    }
                }
            }
        }

        if (!perfect) {
            cout << "NO" << endl;
        } else {
            cout << "YES" << endl;
            for (int i = 0; i < n; i++) {
                cout << colors[i];
            }
            cout << endl;
            cout << "1" << endl;
        }
    }

    return 0;
}
#include <iostream>
#include <vector>

using namespace std;

int main() {
    int t;
    cin >> t;

    while (t--) {
        int n, m;
        cin >> n >> m;

        vector<vector<int>> mat(n, vector<int>(m));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> mat[i][j];
            }
        }

        bool found = false;
        string colors;
        int k;

        for (int i = 0; i < n; i++) {
            if (found) break;

            bool red = false, blue = false;
            for (int j = 0; j < m; j++) {
                if (mat[i][j] % 2 == 0) {
                    if (red) {
                        colors += "B";
                    } else {
                        colors += "R";
                        red = true;
                    }
                } else {
                    if (blue) {
                        colors += "R";
                    } else {
                        colors += "B";
                        blue = true;
                    }
                }
            }

            if (red && blue) {
                found = true;
                k = m - 1;
            }
        }

        if (found) {
            cout << "YES" << endl;
            cout << colors << " " << k << endl;
        } else {
            cout << "NO" << endl;
        }
    }

    return 0;
}
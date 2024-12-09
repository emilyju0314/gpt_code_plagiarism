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
        vector<int> rows(n);

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> matrix[i][j];
            }
        }

        bool perfect = false;

        for (int i = 0; i < n; i++) {
            bool red = false, blue = false;
            for (int j = 0; j < m; j++) {
                if (matrix[i][j] % 2 == 0) {
                    red = true;
                } else {
                    blue = true;
                }
            }

            if (red && blue) {
                perfect = true;
                rows[i] = 1;
            }
        }

        if (perfect) {
            cout << "YES" << endl;
            for (int i = 0; i < n; i++) {
                cout << (rows[i] ? 'R' : 'B');
            }

            cout << endl;

            // Find the value of k
            int k = -1;
            for (int j = 0; j < m; j++) {
                bool left_red = false, left_blue = false;
                bool right_red = false, right_blue = false;

                for (int i = 0; i < n; i++) {
                    if (rows[i] == 1) {
                        if (matrix[i][j] % 2 == 0) {
                            left_red = true;
                        } else {
                            left_blue = true;
                        }
                    } else {
                        if (matrix[i][j] % 2 == 0) {
                            right_red = true;
                        } else {
                            right_blue = true;
                        }
                    }
                }

                if ((!left_red || !right_blue) && (!left_blue || !right_red)) {
                    k = j + 1;
                    break;
                }
            }

            cout << k << endl;
        } else {
            cout << "NO" << endl;
        }
    }

    return 0;
}
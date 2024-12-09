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
        vector<int> red_rows, blue_rows;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> matrix[i][j];
            }
        }

        // Check if there are perfect coloring and cut
        bool perfect = false;
        for (int i = 0; i < n; i++) {
            bool red_found = false, blue_found = false;
            for (int j = 0; j < m; j++) {
                if (matrix[i][j] > matrix[i][0]) {
                    red_found = true;
                } else {
                    blue_found = true;
                }
            }
            if (red_found && blue_found) {
                perfect = true;
                red_rows.push_back(i);
                if (blue_rows.empty()) {
                    for (int j = 0; j < n; j++) {
                        if (j != i) {
                            blue_rows.push_back(j);
                        }
                    }
                }
                break;
            }
        }

        if (perfect) {
            cout << "YES" << endl;
            string colors;
            for (int i = 0; i < n; i++) {
                if (find(red_rows.begin(), red_rows.end(), i) != red_rows.end()) {
                    colors += "R";
                } else {
                    colors += "B";
                }
            }
            cout << colors << " " << m-1 << endl;
        } else {
            cout << "NO" << endl;
        }
    }

    return 0;
}
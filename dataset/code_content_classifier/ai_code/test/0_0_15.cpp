#include <iostream>
#include <vector>

using namespace std;

bool checkField(int n, int m, int k, vector<vector<char>>& field) {
    bool possible = true;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (field[i][j] == '*') {
                bool found = false;
                for (int d = k; d <= n; d++) {
                    bool valid = true;
                    if (i - d + 1 < 0 || i + d - 1 >= n || j - d + 1 < 0 || j + d - 1 >= m) {
                        valid = false;
                    } else {
                        for (int h = 0; h <= d; h++) {
                            if (field[i - h][j - h] != '*' || field[i - h][j + h] != '*') {
                                valid = false;
                                break;
                            }
                        }
                    }
                    if (valid) {
                        found = true;
                        break;
                    }
                }
                if (!found) {
                    possible = false;
                    break;
                }
            }
        }
        if (!possible) {
            break;
        }
    }
    return possible;
}

int main() {
    int t;
    cin >> t;

    for (int i = 0; i < t; i++) {
        int n, m, k;
        cin >> n >> m >> k;

        vector<vector<char>> field(n, vector<char>(m));
        for (int j = 0; j < n; j++) {
            for (int l = 0; l < m; l++) {
                cin >> field[j][l];
            }
        }

        bool possible = checkField(n, m, k, field);
        if (possible) {
            cout << "YES" << endl;
        } else {
            cout << "NO" << endl;
        }
    }

    return 0;
}
#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main() {
    int n, m;
    cin >> n >> m;

    vector<string> field(n);
    for (int i = 0; i < n; i++) {
        cin >> field[i];
    }

    vector<vector<int>> ans(n, vector<int>(m, -1));
    int cur = 0;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (field[i][j] == '#' && ans[i][j] == -1) {
                ans[i][j] = cur;
                if (i > 0 && field[i - 1][j] == '.') {
                    ans[i - 1][j] = cur;
                }
                if (i < n - 1 && field[i + 1][j] == '.') {
                    ans[i + 1][j] = cur;
                }
                if (j > 0 && field[i][j - 1] == '.') {
                    ans[i][j - 1] = cur;
                }
                if (j < m - 1 && field[i][j + 1] == '.') {
                    ans[i][j + 1] = cur;
                }
                cur++;
            }
        }
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (field[i][j] == '.') {
                if (ans[i][j] == -1) {
                    cout << -1 << endl;
                    return 0;
                }
            }
        }
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (field[i][j] == '#') {
                cout << '#';
            } else {
                cout << ans[i][j];
            }
        }
        cout << endl;
    }

    return 0;
}
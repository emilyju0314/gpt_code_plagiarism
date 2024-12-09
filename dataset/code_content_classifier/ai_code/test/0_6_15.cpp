#include <iostream>
#include <vector>

using namespace std;

bool isValid(int i, int j, int n, int m, const vector<string>& field, int k) {
    if (field[i][j] == '.') {
        return false;
    }

    for (int d = 1; d < k; d++) {
        if (i - d < 0 || j - d < 0 || j + d >= m || field[i - d][j - d] == '.' || field[i - d][j + d] == '.') {
            return false;
        }
    }

    return true;
}

int main() {
    int t;
    cin >> t;

    while (t--) {
        int n, m, k;
        cin >> n >> m >> k;

        vector<string> field(n);
        for (int i = 0; i < n; i++) {
            cin >> field[i];
        }

        bool possible = true;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (isValid(i, j, n, m, field, k)) {
                    continue;
                } else {
                    possible = false;
                    break;
                }
            }
            if (!possible) {
                break;
            }
        }

        if (possible) {
            cout << "YES" << endl;
        } else {
            cout << "NO" << endl;
        }
    }

    return 0;
}
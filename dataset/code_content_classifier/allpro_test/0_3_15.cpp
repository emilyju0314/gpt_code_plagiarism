#include <iostream>
#include <vector>
#include <string>

using namespace std;

bool canBeObtained(int n, int m, int k, vector<string>& field) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (field[i][j] == '*') {
                bool found = false;
                for (int d = k; d <= n; d++) {
                    if (i - d + 1 < 0 || i + d >= n || j - d + 1 < 0 || j + d >= m) continue;
                    bool valid = true;
                    for (int h = 0; h <= d; h++) {
                        if (field[i-h][j-h] != '*' || field[i-h][j+h] != '*') {
                            valid = false;
                            break;
                        }
                    }
                    if (valid) {
                        found = true;
                        break;
                    }
                }
                if (!found) return false;
            }
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

        if (canBeObtained(n, m, k, field)) {
            cout << "YES" << endl;
        } else {
            cout << "NO" << endl;
        }
    }

    return 0;
}
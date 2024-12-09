#include <iostream>
#include <vector>

using namespace std;

bool checkField(int n, int m, int k, vector<string>& field) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (field[i][j] == '*') {
                bool valid = false;
                for (int d = k; d <= n; d++) {
                    if (i - d + 1 >= 0 && i + d - 1 < n && j - d + 1 >= 0 && j + d - 1 < m) {
                        bool flag = true;
                        for (int h = 0; h <= d; h++) {
                            if (field[i - h][j - h] != '*' || field[i - h][j + h] != '*') {
                                flag = false;
                                break;
                            }
                        }
                        if (flag) {
                            valid = true;
                            break;
                        }
                    }
                }
                if (!valid) {
                    return false;
                }
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

        if (checkField(n, m, k, field)) {
            cout << "YES" << endl;
        } else {
            cout << "NO" << endl;
        }
    }

    return 0;
}
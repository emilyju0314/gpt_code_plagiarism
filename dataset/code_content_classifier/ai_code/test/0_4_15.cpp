#include <iostream>
#include <vector>
#include <string>

using namespace std;

bool isValid(vector<string>& field, int n, int m, int k) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (field[i][j] == '*') {
                if (i+k >= n || j+2*k-1 >= m) {
                    return false;
                }
                for (int x = i; x < i + k; x++) {
                    for (int y = j; y < j + 2*k - 1; y++) {
                        if (field[x][y] == '.') {
                            return false;
                        }
                    }
                }
                for (int x = i+k; x < n; x++) {
                    for (int y = j+k; y < j+k+1; y++) {
                        if (field[x][y] == '*') {
                            return false;
                        }
                    }
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

        if (isValid(field, n, m, k)) {
            cout << "YES" << endl;
        } else {
            cout << "NO" << endl;
        }
    }

    return 0;
}
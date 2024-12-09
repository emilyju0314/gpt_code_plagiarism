#include <iostream>
#include <vector>

using namespace std;

bool canBeObtained(vector<string>& field, int n, int m, int k) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (field[i][j] == '*') {
                int d = 0;
                while (i-d >= 0 && i+d < n && j-d >= 0 && j+d < m && field[i-d][j-d] == '*' && field[i-d][j+d] == '*' && field[i+d][j-d] == '*' && field[i+d][j+d] == '*') {
                    field[i-d][j-d] = '.';
                    field[i-d][j+d] = '.';
                    field[i+d][j-d] = '.';
                    field[i+d][j+d] = '.';
                    d++;
                }
                if (d < k) {
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

        if (canBeObtained(field, n, m, k)) {
            cout << "YES" << endl;
        } else {
            cout << "NO" << endl;
        }
    }

    return 0;
}
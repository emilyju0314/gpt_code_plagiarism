#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main() {
    int n, m;
    cin >> n >> m;

    vector<vector<bool>> exitable(n, vector<bool>(m, false));
    for (int i = 0; i < n; i++) {
        string row;
        cin >> row;
        for (int j = 0; j < m; j++) {
            if (row[j] == '.') {
                exitable[i][j] = true;
            }
        }
    }

    int q;
    cin >> q;

    for (int k = 0; k < q; k++) {
        int x1, x2;
        cin >> x1 >> x2;
        x1--; x2--;

        bool determinable = true;
        for (int i = 0; i < n; i++) {
            bool exitable_in_range = false;
            for (int j = x1; j <= x2; j++) {
                if (exitable[i][j]) {
                    exitable_in_range = true;
                    break;
                }
            }
            if (!exitable_in_range) {
                determinable = false;
                break;
            }
        }

        if (determinable) {
            cout << "YES" << endl;
        } else {
            cout << "NO" << endl;
        }
    }

    return 0;
}
#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n, m;
    cin >> n >> m;

    vector<vector<int>> A(n, vector<int>(m));
    vector<vector<int>> B(n, vector<int>(m, 0));

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> A[i][j];
        }
    }

    vector<pair<int, int>> operations;

    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < m - 1; j++) {
            if (A[i][j] == 1) {
                B[i][j] = 1;
                B[i+1][j] = 1;
                B[i][j+1] = 1;
                B[i+1][j+1] = 1;
                operations.emplace_back(i+1, j+1);
            }
        }
    }

    bool possible = true;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (A[i][j] != B[i][j]) {
                possible = false;
            }
        }
    }

    if (!possible) {
        cout << -1;
    } else {
        cout << operations.size() << endl;
        for (auto op : operations) {
            cout << op.first << " " << op.second << endl;
        }
    }

    return 0;
}
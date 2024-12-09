#include <iostream>
#include <vector>

#define MOD 998244353

using namespace std;

int main() {
    int n, m;
    cin >> n >> m;

    vector<vector<int>> matrix(n, vector<int>(m, 0));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> matrix[i][j];
        }
    }

    int r, c;
    cin >> r >> c;
    r--; c--;

    long long ans = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (matrix[i][j] < matrix[r][c]) {
                long long dist = (i - r) * (i - r) + (j - c) * (j - c);
                ans = (ans + dist) % MOD;
            }
        }
    }

    cout << ans << endl;

    return 0;
}
#include <bits/stdc++.h>
using namespace std;

const int M = 3e3;
int n, m, mat[M][M];
long long memo[M][M][4];

long long solve(int i, int j, int cnt) {
    if (i == n || j == m)
        return 0;
    long long &r = memo[i][j][cnt];
    if (r == -1) {
        r = max(solve(i + 1, j, 0), solve(i, j + 1, cnt));
        if (cnt < 3 && mat[i][j])
            r = max(r, mat[i][j] + max(solve(i + 1, j, 0), solve(i, j + 1, cnt + 1)));
    }
    return r;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    memset(memo, -1, sizeof memo);
    int k;
    cin >> n >> m >> k;
    while (k--) {
        int i, j, x;
        cin >> i >> j >> x;
        mat[i - 1][j - 1] = x;
    }
    cout << solve(0, 0, 0) << '\n';
}
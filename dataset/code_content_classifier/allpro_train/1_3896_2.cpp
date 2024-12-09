#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int h, w;
bool valid(int s, int t) {
    if (s >= 0 && s < h && t >= 0 && t < w) return 1;
    return 0;
}
int main() {
    int i, j;
    cin >> h >> w;
    char a[h][w];
    for (i = 0; i < h; i++) {
        for (j = 0; j < w; j++) {
            cin >> a[i][j];
        }
    }

    int dx[4] = {-2, -1, -1, 0};
    int dy[4] = {0, -1, -1, -2};
    int mdx[4] = {-1, -1, 0, 0};
    int mdy[4] = {0, 0, -1, -1};

    map<ll, ll> ma[h][w];

    ma[0][0][a[0][0] - '0'] = 0;

    for (i = 0; i < h; i++) {
        for (j = 0; j < w; j++) {
            if ((i + j) % 2 == 1) continue;
            if (i == 0 && j == 0) continue;
            for (int k = 0; k < 4; k++) {
                int x = i + dx[k];
                int y = j + dy[k];
                int mx = i + mdx[k];
                int my = j + mdy[k];
                if (!valid(x, y)) continue;
                int z = a[i][j] - '0';

                for (auto it = ma[x][y].begin(); it != ma[x][y].end(); ++it) {
                    if (a[mx][my] == '+')
                        ma[i][j][z] = max(ma[i][j][z], it->first + it->second);
                    else
                        ma[i][j][z * it->first] = max(ma[i][j][z * it->first], it->second);
                    if (it->second + it->first > pow(10, 15)) {
                        cout << -1 << endl;
                        return 0;
                    }
                }
            }
        }
    }

    ll ans = 0;
    for (auto it = ma[h - 1][w - 1].begin(); it != ma[h - 1][w - 1].end(); ++it) {
        ans = max(ans, it->first + it->second);
    }
    if (ans > pow(10, 15)) {
        cout << -1 << endl;
        return 0;
    }
    cout << ans << endl;
}

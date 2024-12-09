#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> ii;
const int N = 4005;

int h, w, n, m;
short l[N][N], r[N][N];
short d[N][N], u[N][N];
int bit[N];
bool a[N][N];
long long res;
vector<ii> v;

void upd(int x) {
    for (int i = x; i < N; i += i & -i) bit[i]++;
}

long long get(int x) {
    long long ans = 0;
    for (int i = x; i > 0; i -= i & -i) ans += bit[i];
    return ans;
}

long long get(int l, int r) {
    if (l > r) return 0;
    return get(r) - get(l - 1);
}

void solve() {
    vector<ii> go[2];
    int sz = v.size();
    // check
    /*
    cout << "Check\n";
    for (int i = 0; i < sz; ++i) {
        cout << v[i].first << ' ' << v[i].second << '\n';
    }
    */
    // prepare
    for (int i = 0; i < sz; ++i) {
        go[0].push_back(ii(l[v[i].first][v[i].second], v[i].first));
        go[1].push_back(ii(r[v[i].first][v[i].second], v[i].first));
    }
    for (int i = 0; i < 2; ++i) {
        sort(go[i].begin(), go[i].end(), greater<ii>());
    }
    // min in 0
    int cur = 0;
    memset(bit, 0, sizeof bit);
    for (int i = 0; i < sz; ++i) {
        while (cur < sz && go[1][cur].first >= go[0][i].first) upd(go[1][cur++].second);
        res += get(go[0][i].second - go[0][i].first + 1, go[0][i].second - n + 1);
    }
    // min in 1
    cur = 0;
    memset(bit, 0, sizeof bit);
    for (int i = 0; i < sz; ++i) {
        while (cur < sz && go[0][cur].first > go[1][i].first) upd(go[0][cur++].second);
        res += get(go[1][i].second + n - 1, go[1][i].first + go[1][i].second - 1);
    }
}

void init(int x, int y) {
    v.clear();
    for (int i = 0; ; ++i) {
        if (x + i > h || y + i > w) return;
        v.push_back(ii(x + i, y + i));
    }
}

int main() {
    ios::sync_with_stdio(false);
    // in
    cin >> h >> w >> n >> m;
    for (int i = 0; i < m; ++i) {
        int x, y; cin >> x >> y; a[x][y] = 1;
    }
    // prepare
    for (int i = 1; i <= h; ++i) {
        for (int j = 1; j <= w; ++j) {
            if (a[i][j]) l[i][j] = u[i][j] = 0;
            else l[i][j] = l[i][j - 1] + 1, u[i][j] = u[i - 1][j] + 1;
        }
    }
    for (int i = h; i >= 1; --i) {
        for (int j = w; j >= 1; --j) {
            if (a[i][j]) r[i][j] = u[i][j] = 0;
            else r[i][j] = r[i][j + 1] + 1, d[i][j] = d[i + 1][j] + 1;
        }
    }
    for (int i = 1; i <= h; ++i) {
        for (int j = 1; j <= w; ++j) {
            l[i][j] = min(l[i][j], u[i][j]);
            r[i][j] = min(r[i][j], d[i][j]);
        }
    }
    // solve
    for (int i = 1; i <= w; ++i) {
        init(1, i), solve();
    }
    for (int i = 2; i <= h; ++i) {
        init(i, 1), solve();
    }
    // out
    cout << res << '\n';
}
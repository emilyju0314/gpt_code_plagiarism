#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using vll = vector<ll>;
using vvll = vector<vll>;
using vc = vector<char>;
using vvc = vector<vc>;
using pll = pair<ll, ll>;
using stkll = vector<pll>;
const ll INF = 1LL << 60;
const ll MOD = 1e9 + 7;
#define rep(i, n) for (ll i = 0; i < (n); i++)
template<typename T1,typename T2> inline void chmin(T1 &a,T2 b){if(a>b) a=b;}
template<typename T1,typename T2> inline void chmax(T1 &a,T2 b){if(a<b) a=b;}
#ifndef ONLINE_JUDGE
    #define debug(x) cerr << #x << ": " << x << endl;
#else
    #define debug(x)
#endif

struct L {
    int a, b, c;
    L(int a = 0, int b = 0, int c = 0): a(a), b(b), c(c) {}
};

const int dx[4] = {-1, 0, 1, 0};
const int dy[4] = {0, -1, 0, 1};

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    cout << fixed << setprecision(20);

    int n, m;
    cin >> n >> m;
    map<int, int> mpx, mpy;
    mpx[0] = 0;
    mpy[0] = 0;

    vector<L> lh, lv;
    rep(i,n) {
        int a, b, c;
        cin >> a >> b >> c;
        mpx[a] = 0;
        mpx[b] = 0;
        mpy[c] = 0;
        lh.emplace_back(a, b, c);
    }
    rep(i,m) {
        int a, b, c;
        cin >> c >> a >> b;
        mpy[a] = 0;
        mpy[b] = 0;
        mpx[c] = 0;
        lv.emplace_back(a, b, c);
    }

    vector<int> xs, ys;
    for(auto& p : mpx) {
        p.second = xs.size();
        xs.push_back(p.first);
    }
    for(auto& p : mpy) {
        p.second = ys.size();
        ys.push_back(p.first);
    }

    int w = xs.size() * 2;
    int h = ys.size() * 2;
    vector<vector<int>> d(w, vector<int>(h, 0));
    rep(i,n) {
        int a = mpx[lh[i].a] * 2;
        int b = mpx[lh[i].b] * 2;
        int c = mpy[lh[i].c] * 2;
        for(int x = a; x <= b; x++) d[x][c] = -1;
    }
    rep(i,m) {
        int a = mpy[lv[i].a] * 2;
        int b = mpy[lv[i].b] * 2;
        int c = mpx[lv[i].c] * 2;
        for(int y = a; y <= b; y++) d[c][y] = -1;
    }

    queue<pair<int, int>> q;
    int sx = mpx[0] * 2;
    int sy = mpy[0] * 2;
    d[sx][sy] = 1;
    q.emplace(sx, sy);
    while(!q.empty()) {
        int x = q.front().first;
        int y = q.front().second;
        q.pop();
        rep(i,4) {
            int nx = x + dx[i], ny = y + dy[i];
            if(nx < 0 || nx >= w) continue;
            if(ny < 0 || ny >= h) continue;
            if(d[nx][ny] != 0) continue;
            d[nx][ny] = 1;
            q.emplace(nx, ny);
        }
    }

    ll ans = 0;
    rep(x, w) rep(y, h) {
        if (d[x][y] != 1) continue;
        // 端にたどり着けたらINF
        if (x == 0 || x == w-1 || y == 0 || y == h-1) {
            cout << "INF" << endl;
            return 0;
        }
        // 線分用のマスは幅ゼロ扱い
        if(x % 2 == 0 || y % 2 == 0) continue;

        ll wx = xs[x/2+1] - xs[x/2];
        ll wy = ys[y/2+1] - ys[y/2];
        ans += wx * wy;
    }
    cout << ans << endl;
}

// nauynix
// 23/04/2021
#include <bits/stdc++.h>
using namespace std;
#define rep(i, begin, end) for (__typeof(end) i = (begin) - ((begin) > (end)); i != (end) - ((begin) > (end)); i += 1 - 2 * ((begin) > (end)))
#define all(x) (x).begin(), (x).end()
#define pb push_back
#define fi first
#define se second
typedef pair<int, int> PII;
typedef vector<int> VI;
typedef vector<string> VS;
typedef vector<PII> VII;
typedef vector<VI> VVI;
typedef long long int  ll;
const int INF = 1e9 + 7;
const int mod = 1e9 + 7;
ll powmod(ll a,ll b) {ll res=1;a%=mod; assert(b>=0); for(;b;b>>=1){if(b&1)res=res*a%mod;a=a*a%mod;}return res;}
int nxt() {int x;cin >> x;return x;}

struct MaxFlow
{
    int N;
    vector<vector<ll>> cap, adj;

    MaxFlow(int _N) {
        N = _N;
        cap.resize(N, vector<ll>(N));
        adj.resize(N);
    }

    void addEdge(int u, int v, int c) {
        adj[u].push_back(v);
        adj[v].push_back(u);
        cap[u][v] += c;
    }

    ll flow(int st, int nd) {
        queue<pair<int, ll>> bfs;
        vector<int> parent(N, -1);
        vector<bool> visited(N, false);

        bfs.push(make_pair(st, LLONG_MAX));
        parent[st] = -1;
        visited[st] = true;
        while (!bfs.empty()) {
            pair<int, ll> now = bfs.front();
            bfs.pop();
            if (now.first == nd) {
                int ix = now.first;
                while (ix != st) {
                    cap[parent[ix]][ix] -= now.second;
                    cap[ix][parent[ix]] += now.second;
                    ix = parent[ix];
                }
                return now.second;
            }
            for (int v : adj[now.first]) {
                if (cap[now.first][v] > 0) {
                    ll f = min(cap[now.first][v], now.second);
                    if (!visited[v]) {
                        parent[v] = now.first;
                        visited[v] = true;
                        bfs.push(make_pair(v, f));
                    }
                }
            }
        }
        return 0;
    }

    ll countMaxFlow(int st, int nd) {
        ll res = 0;
        while (1) {
            ll f = flow(st, nd);
            if (f == 0) break;
            res += f;
        }
        return res;
    }
};
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    vector<array<int, 3>> a[4];
    int n = nxt();
    map<PII, int> m;
    int cnt = 0;
    ll sum = 0;
    rep (i, 0, n) {
        array<int, 3> b;
        cin >> b[0] >> b[1] >> b[2];
        m[{b[0], b[1]}] = cnt;
        cnt+=2;
        if (b[0]%2 == 0 && b[1] % 2 == 0) a[1].pb(b);
        else if (b[1] % 2 == 0) a[0].pb(b);
        else if (b[0]%2 == 0) a[2].pb(b);
        else a[3].pb(b);
        sum += b[2];
    }
    // 0 is source, 1 is target
    // s - a[0] - a[0] - a[1] - a[1] - a[2] - a[2] - a[3] - a[3] - t
    MaxFlow mf(2 + n*2);
    int s = 2 + n*2 - 2;
    int t = 2 + n*2 - 1;
    for (auto &[x, y, w] : a[0]) {
        mf.addEdge(s, m[{x, y}], INF);
    }
    for (int i = 0; i < 4; i++) {
        for (auto &[x, y, w] : a[i]) {
            mf.addEdge(m[{x,y}], m[{x, y}]+1, w);
        }
    }
    for (int i = 0; i < 3; i++) {
        for (auto &[x1, y1, _] : a[i]) {
            for (auto &[x2, y2, _] : a[i+1]) {
                if (abs(x1-x2) + abs(y1-y2) == 1) {
                    mf.addEdge(m[{x1,y1}]+1, m[{x2,y2}], INF);
                }
            }
        }
    }
    for (auto &[x, y, w] : a[3]) {
        mf.addEdge(m[{x, y}]+1, t, INF);
    }
    printf("%lld\n", sum - mf.countMaxFlow(s, t));
    return 0;
}


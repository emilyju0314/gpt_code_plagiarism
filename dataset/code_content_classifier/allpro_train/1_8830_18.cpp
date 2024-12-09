#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef pair<ll, ll> P;
typedef pair<ll, pair<ll, ll> > P3;

const ll MOD = ll(1e9 + 7);
const ll LLINF = LLONG_MAX;
const int IINF = INT_MAX;
const int MAX_V = int(2e5) + 5;
const double EPS = 1e-8;
const int di[] = {0, 1, 0, -1}, dj[] = {1, 0, -1, 0};
string dir[] = {"R", "D", "L", "U"};
#define REP(i, n) for (int i = 0; i < n; i++)
#define REPR(i, n) for (int i = n; i >= 0; i--)
#define FOR(i, m, n) for (ll i = m; i < n; i++)
#define ALL(v) (v).begin(), (v).end()

struct edge {
    ll from, to, a, b;
    edge(ll u, ll v, ll a, ll b) : from(u), to(v), a(a), b(b){};
};

vector<edge> G[MAX_V];
ll dmin[MAX_V];

void add_edge(ll u, ll v, ll a, ll b) {
    G[u].push_back(edge(u, v, a, b));
    G[v].push_back(edge(v, u, a, b));
}

ll f(ll b, ll a, ll x) { return ll(ceil(b / double(a + x) + double(x))); }

void dijkstra(int s) {
    priority_queue<P, vector<P>, greater<P> > que;  //小さいものから取り出す
    fill(dmin, dmin + MAX_V, LLINF);
    dmin[s] = 0;
    que.push(P(0, s));

    while (!que.empty()) {
        P p = que.top();
        que.pop();
        int v = p.second;
        if (dmin[v] < p.first) continue;
        for (auto &e : G[v]) {
            ll k = max(0.0, pow(e.b, 0.5) - (e.a + dmin[v])), cost;
            cost = f(e.b, e.a + dmin[v], 0);
            if (k > 0) {
                cost = min(cost,min(f(e.b,e.a+dmin[v],floor(k)),f(e.b,e.a+dmin[v],ceil(k))));
            }
            if (dmin[e.to] > dmin[v] + cost) {
                dmin[e.to] = dmin[v] + cost;
                que.push(P(dmin[e.to], e.to));
            }
        }
    }
}

int main() {
    ll n, m, s, g;
    cin >> n >> m >> s >> g;
    REP(i, m) {
        ll u, v, a, b;
        cin >> u >> v >> a >> b;
        add_edge(u, v, a, b);
    }
    dijkstra(s);
    cout << (dmin[g]!=LLINF?dmin[g]:-1) << endl;
    return 0;
}


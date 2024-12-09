#include <bits/stdc++.h>
#define in(x) freopen(x, "r", stdin)
#define out(x) freopen(x, "w", stdout)
//#pragma GCC optimize("Ofast")
//#pragma GCC optimize("unro-loops")
//#pragma GCC optimize("-O3")
#define F first
#define S second
#define pb push_back
#define M ll(1e9 + 7)
#define sz(x) (ll)x.size()
#define re return
#define oo ll(1e9)
#define el '\n'
#define pii pair <int, int>
#define all(x) (x).begin(), (x).end()
#define arr_all(x, n) (x + 1), (x + 1 + n)
#define vi vector<ll>
#define pi acos(-1)
#define eps (ld)1e-6
#define det(a, b, c, d) (a * d - b * c)
using namespace std;
//using namespace __gnu_pbds;
//typedef tree <ll, null_type, less_equal <ll> , rb_tree_tag, tree_order_statistics_node_update> ordered_set;
typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;

const int N = 2e5 + 500;

int pr[N], a[N], mx[N];
vector <pii> g[N];
vector <int> c[N];
int n, q, s, d;

int f(int v) {return (pr[v] == v ? v : pr[v] = f(pr[v]));}
bool link(int v, int u) {
    v = f(v); u = f(u);

    if (v == u){
        return 0;
    }

    pr[u] = v;
    return 1;
}

void dfs(int v, int pr) {
    for (auto u : g[v]) {
        int to = u.F;
        int w = u.S;

        if (to == pr) {
            continue;
        }

        mx[to] = max(mx[v], w);
        dfs(to, v);
    }
}

int get(int x, int y) {
    if (x < y) {
        swap(x, y);
    }
    x -= y;

    if (x < d) {
        return d - x;
    }
    return x - d;
}

void upd(pii b, pair <int, pii> &p, int v) {
    pair <int, pii> c = {get(a[v], b.F), {v, b.S}};

    p = min(c, p);
}

int main()
{
    srand(time(0));
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cout.precision(12);
    cout << fixed;
//    in("arithm.in");
//    out("arithm.out");
//    in("13.in");
//    out("output.txt") ;

    cin >> n >> q >> s >> d;

    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }

    for (int i = 1; i <= n; i++) {
        pr[i] = i;
    }
    int cnt = 0;
    set <pii> wc;
    for (int i = 1; i <= n; i++) {
        wc.insert({a[i], i});
    }

    while (cnt < n - 1) {
        vector <pair <int, pii> > e;

        for (int i = 1; i <= n; i++) {
            c[i].clear();
        }

        for (int i = 1; i <= n; i++) {
            c[f(i)].pb(i);
        }

        for (int i = 1; i <= n; i++) {
            if (!sz(c[i]))  {
                continue;
            }

            for (auto v : c[i]) {
                wc.erase({a[v], v});
            }

            pair <int, pii> b = {1e9, {1e9, 1e9}};

            for (auto v : c[i]) {
                auto it = wc.lower_bound({a[v] - d, 0});

                if (it != wc.end()) {
                    upd(*it, b, v);
                }
                if (it != wc.begin()) {
                    --it; upd(*it, b, v);
                }

                it = wc.lower_bound({a[v] + d, 0});

                if (it != wc.end()) {
                    upd(*it, b, v);
                }
                if (it != wc.begin()) {
                    --it; upd(*it, b, v);
                }
            }

            if (b.F != 1e9) {
                e.pb(b);
            }

            for (auto v : c[i]) {
                wc.insert({a[v], v});
            }
        }

        for (auto ed : e) {
            int v = ed.S.F;
            int u = ed.S.S;
            int w = ed.F;

            if (link(v, u)) {
                g[v].pb({u, w});
                g[u].pb({v, w});
                cnt++;
            }
        }
    }

    dfs(s, -1);
    while (q--) {
        int v, k;
        cin >> v >> k;

        if (mx[v] <= k) {
            cout << "Yes" << el;
        }
        else {
            cout << "No" << el;
        }
    }
}

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;
const ll MOD = 1e9 + 7;
const int iinf = 1 << 29;
const long long llinf = 1ll << 60;
const double PI = 3.14159265;
#define pb push_back
#define ff first
#define ss second
#define sz(a) ((int)(a).size())
#define all(x) (x).begin(),(x).end()
mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());
ll mrand(ll B) {
  return (ull)rng() % B;
}

ll cross(pair<ll, ll> p1, pair<ll, ll> p2) {
    return p1.first*p2.second - p2.first*p1.second;
}

bool online(pair<ll, ll> a, pair<ll, ll> b, pair<ll, ll> c) {
    pair<ll, ll> p1{b.first-a.first, b.second-a.second};
    pair<ll, ll> p2{c.first-a.first, c.second-a.second};
    return cross(p1, p2) == 0;
}

void z_func(vector<int> &z, vector<int> &s, int n) {
    int L = 0, R = 0;
    for (int i = 1; i < n; i++) {
        if (i > R) {
            L = R = i;
            while (R < n && s[R-L] == s[R]) R++;
            z[i] = R-L; R--;
        } else {
            int k = i-L;
            if (z[k] < R-i+1) z[i] = z[k];
            else {
                L = i;
                while (R < n && s[R-L] == s[R]) R++;
                z[i] = R-L; R--;
            }
        }
    }
}

const int N = 505;
int n;
int next_id;
int ans[N*N];
int sal[N*N];
int v[N][N];

int solve(set<int> &nodes) {
    // cout << "solve: ";
    // for (auto s : nodes) cout << s << ' ';
    // cout << '\n' << endl;
    if (sz(nodes) == 1) {
        int id = *(nodes.begin());
        sal[id] = v[id][id];
        return id;
    }

    int max_val = -1;
    for (auto node : nodes) {
        for (int i = 1; i <= n; i++) {
            if (i == node || !nodes.count(i)) continue;
            max_val = max(max_val, v[i][node]);
        }
    }

    vector<set<int>> sets;
    //cout << "max_val: " << max_val << endl;
    for (auto node : nodes) {
        //cout << "processing node " << node << endl;
        bool found_set = false;
        for (auto &s : sets) {
            bool can_use_this_set = true;
            for (auto u : s) {
                if (v[u][node] == max_val) {
                    can_use_this_set = false;
                    break;
                }
            }
            if (can_use_this_set) {
                //cout << "A" << endl;
                s.insert(node);
                found_set = true;
                break;
            }
        }
        
        if (!found_set) {
            set<int> tmp; tmp.insert(node);
            sets.pb(tmp);
            //cout << "B" << endl;
        }
    }

    int root = next_id++;
    sal[root] = max_val;
    for (auto s : sets) {
        int ret = solve(s);
        ans[ret] = root;
    }
    return root;
}

void work() {
    cin >> n; next_id = n + 1;
    set<int> s;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            cin >> v[i][j];
        }
        s.insert(i);
    }

    int root = solve(s);
    cout << next_id - 1 << '\n';
    for (int i = 1; i < next_id; i++) cout << sal[i] << ' ';
    cout << '\n' << root << '\n';
    for (int i = 1; i < next_id; i++) {
        if (i == root) continue;
        cout << i << ' ' << ans[i] << '\n';
    }
}

int main() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    //int nt; cin>>nt; while (nt--) work();
    work();
    return 0;
}

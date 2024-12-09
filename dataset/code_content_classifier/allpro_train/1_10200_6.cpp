#include <bits/stdc++.h>
#define int long long
#define ll long long
using ull = unsigned long long;
using namespace std;
const int INF = 1e10;
const int MOD = 1e9 + 7;
#define dump(x)                             \
    if (dbg) {                              \
        cerr << #x << " = " << (x) << endl; \
    }
#define overload4(_1, _2, _3, _4, name, ...) name
#define FOR1(n) for (ll i = 0; i < (n); ++i)
#define FOR2(i, n) for (ll i = 0; i < (n); ++i)
#define FOR3(i, a, b) for (ll i = (a); i < (b); ++i)
#define FOR4(i, a, b, c) for (ll i = (a); i < (b); i += (c))
#define FOR(...) overload4(__VA_ARGS__, FOR4, FOR3, FOR2, FOR1)(__VA_ARGS__)
#define FORR(i, a, b) for (int i = (a); i <= (b); ++i)
#define bit(n, k) ((n >> k) & 1) /*nのk bit目*/
template <class T>
bool chmin(T& a, const T& b) {
    if (a > b) {
        a = b;
        return 1;
    } else
        return 0;
}
template <class T>
bool chmax(T& a, const T& b) {
    if (a < b) {
        a = b;
        return 1;
    } else
        return 0;
}
void Yes(bool flag = true) {
    if (flag)
        cout << "Yes" << endl;
    else
        cout << "No" << endl;
}
void No(bool flag = true) {
    Yes(!flag);
}
void YES(bool flag = true) {
    if (flag)
        cout << "YES" << endl;
    else
        cout << "NO" << endl;
}
void NO(bool flag = true) {
    YES(!flag);
}
#define pb push_back
#define mp make_pair
#define lb lower_bound
#define ub upper_bound
#define all(v) (v).begin(), (v).end()
#define SZ(x) ((int)(x).size())
#define P pair<int, int>
//#define V vector<int>
//#define S set<int>
#define itn int
bool dbg = false;

int N, K, a[100];
P tmp[111];
vector<itn> ans;

void solve() {
    itn bef = -1;
    K++;
    while (K--) {
        itn idx = (bef == 0);
        FOR(N)
        if (i != bef && a[i] < a[idx])
            idx = i;
        FOR(N)
        if (i != idx && i != bef) {
            ans.emplace_back(i);
            a[i]--;
        }
        ans.emplace_back(idx);
        a[idx]--;
        bef = idx;
    }
    int MIN = INF;
    FOR(N) {
        chmin(MIN, a[i]);
        cerr << a[i] << " ";
    }
    cerr << endl;
    if (MIN < 0) {
        cout << -1 << endl;
        return;
    }
    cout << ans.size() << endl;


    FOR((int)ans.size())
    cout << ans[i] + 1 << " ";
    cout << endl;
}


/*
void solve() {
    auto compare = [](P a, P b) {
        return a.first > b.first;
    };

    priority_queue<P, vector<P>, decltype(compare)> que{compare};
    FOR(N)
    que.push(P{a[i], i + 1});

    bool flag = true;

    P bef;
    P open = que.top();
    que.pop();

    K++;
    while (K--) {
        int NN = que.size();

        FOR(NN) {
            tmp[i] = que.top();
            que.pop();
            tmp[i].first--;
            ans.emplace_back(tmp[i].second);
        }
        FOR(i, 1, NN) {
            que.push(tmp[i]);
        }

        if (NN != N - 1) {
            que.push(bef);
        }

        ans.emplace_back(open.second);
        bef = open;

        open = tmp[0];
        open.first--;
    }
    int MIN = 0;
    chmin(MIN, bef.first);
    chmin(MIN, open.second);
    while (!que.empty()) {
        chmin(MIN, que.top().first);
        que.pop();
    }
    if (MIN >= 0) {
        for (auto& a : ans)
            cout << a << " ";
        cout << endl;
    } else {
        cout << -1 << endl;
    }
}
*/

signed main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    cin >> N >> K;
    FOR(N)
    cin >> a[i];

    solve();
    return 0;
}

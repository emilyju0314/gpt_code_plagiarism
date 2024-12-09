#include <bits/stdc++.h>

#define iter_all(x) x.begin(), c.end()
#define umap unordered_map
#define uset unordered_set

using namespace std;

typedef long long int ll;

auto io_speed = []() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    return 0;
}();

ll pow_mod(ll a, ll e, ll mod) {
    ll res = 1;
    while(e) {
        if(e&1) res = res * a%mod;
        e>>=1;
        a=a*a%mod;
    }
    return res;
}

ll inv_mod(ll b, ll m) {
    ll a=m, x=0, y=1, r, q;
    while(b) {
        r = a%b;
        q = a/b;
        a = b;
        b = r;
        r = x;
        x = y;
        y = r-q*y;
    }
    x+=m;
    return x%m;
}

ll gcd(ll a, ll b) {
    return b == 0 ? a : gcd(b, a%b);
}

const int N = 2e5+10;
vector<int> facts[N];

void solve() {
    int n;
    cin >> n;
    vector<int> arr(n);
    for(auto &x : arr) cin >> x;
    sort(arr.begin(), arr.end());
    vector<int> groups(N, 0);
    int res = 0;
    for(auto x : arr) {
        int mx = 0;
        // cout << x << " | ";
        for(auto y : facts[x]) {
            // cout << y << ", " << groups[y] << " | ";
            if(groups[y]) {
                if(groups[mx] < groups[y]) {
                    mx = y;
                }
            }
        }
        // cout << endl;
        groups[x] = groups[mx] + 1;
        res = max(groups[x], res);
        // cout << groups[x] << ", " << mx << endl;
    }
    // cout << endl;
    cout << n - res << endl;
}

int main() {

    for(int i = 1; i < N; i++) {
        for(int j = 1; j*j <= i; j++) {
            if(i%j==0) {
                int q = i/j;
                facts[i].push_back(j);
                if(j!=q) facts[i].push_back(q);
            }
        }
    }

    int t = 1;
    cin >> t;
    // cout << t << endl;
    for(int i = 1; i <= t; i++) {
        // cout << "Case #"<<i<<": ";
        solve();
    }
}

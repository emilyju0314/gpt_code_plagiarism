#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <unordered_map>
#include <unordered_set>
#include <queue>
#include <stack>
#include <algorithm>
#include <numeric>
#include <math.h>
#include <iomanip>
#include <cstring>

// #pragma GCC optimize("Ofast")
#pragma GCC target("avx2")

using namespace std;

// #include <ext/pb_ds/assoc_container.hpp>
// #include <ext/pb_ds/tree_policy.hpp>
// using namespace __gnu_pbds;

// template <typename T>
// using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

template <class T>
using pq = priority_queue<T>;
template <class T>
using pqg = priority_queue<T, vector<T>, greater<T>>;

#define pb push_back
#define eb emplace_back
#define endl "\n"
#define ll long long
#define ld long double
#define pii pair<int, int>
#define pll pair<ll, ll>
#define ff first
#define ss second

#define add(a, b) (a + b >= MOD ? a + b - MOD : a + b)
#define all(x) (x).begin(), (x).end()
#define unique(x) sort(all(x)), (x).erase(unique(all(x)), (x).end())
#define tolower(x) transform(all(x), x.begin(), ::tolower)
#define toupper(x) transform(all(x), x.begin(), ::toupper)
#define remove_all(x, y) x.erase(remove(all(x), char(y)), x.end());

#define input(in) freopen(in, "r", stdin)
#define output(out) freopen(out, "w", stdout)

const int INF = 1e9;
const ll LINF = 1e17;
// const double EPS = 1e-10;
// const double gam = 0.5772156649015328606; //euler's constant
// const double PI = acos(-1.0);
const int dx[8] = {-1, 0, 0, 1, 1, 1, -1, -1};
const int dy[8] = {0, -1, 1, 0, 1, -1, 1, -1};
// const int dxx[8] = {1, 1, 2, 2, -1, -1, -2, -2};
// const int dyy[8] = {2, -2, 1, -1, 2, -2, 1, -1};
const int MOD = 998244353;
const int maxn = 1e5;
//mt19937 rng(chrono::system_clock::now().time_since_epoch().count());

ll binexpo(ll base, ll power)
{
    ll ret(1ll);
    while (power)
    {
        if (power & 1)
            ret = (ret * base * 1ll) % MOD;
        base = base * base * 1ll % MOD;
        power >>= 1;
    }
    return ret;
}

void solve()
{
    vector<int> fact(maxn + 5); // ifact(maxn + 5);
    fact[0] = 1;
    for (int i = 1; i <= maxn; i++)
        fact[i] = fact[i - 1] * 1ll * i % MOD;

    // ifact[maxn] = binexpo(fact[maxn], MOD - 2);
    // for (int i = maxn - 1; i >= 0; i--)
    //     ifact[i] = ifact[i + 1] * 1ll * (i + 1) % MOD;

    int t;
    cin >> t;
    string s;
    for (int i = 0, n; i < t; i++)
    {
        cin >> n >> s;
        int d(0), z(0); // d = double ones, z = zeros
        for (int i = 0; i < n; i++)
            if (s[i] == '0')
                z++;
            else if (i + 1 < n and s[i] == '1' and s[i + 1] == '1')
                d++, i++;

        // cout << (fact[d + z] * 1ll * ifact[d] % MOD) * ifact[z] % MOD << endl;
        cout << fact[d + z] * 1ll * binexpo(fact[d], MOD - 2) % MOD * binexpo(fact[z], MOD - 2) % MOD << endl;
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);

    int t(1);
    // cin >> t;
    while (t--)
        solve();

    return 0;
}
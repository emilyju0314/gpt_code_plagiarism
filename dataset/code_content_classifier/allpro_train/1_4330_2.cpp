#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <queue>
#include <map>
#include <set>
#include <cmath>
#include <numeric>
#include <iomanip>
#include <stack>
#include <complex>
#include <functional>
#include <tuple>

using namespace std;

#define Rep(i,a,b) for(ll i = a; i < b; ++i)
#define rep(i,b) Rep(i,0,b)
#define allof(a) (a).begin(), (a).end()

using ll = long long;

constexpr int inf = 1e9 + 7;
constexpr ll infll = 1ll << 60ll;
constexpr ll mod = 1e9 + 7;
// 0~3までは右左下上 4~7までは斜め
constexpr int dx[] = { 1, 0, -1, 0, 1, 1, -1, -1 };
constexpr int dy[] = { 0, -1, 0, 1, 1, -1, -1, 1 };

template<typename T> bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }
template<typename T> bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }



int main() {

    ll n;
    cin >> n;
    double k;
    cin >> k;
    vector<double> s(n);
    rep(i, n) cin >> s[i];

    // 0がある
    bool is_zero = false;
    // すべてk以上
    bool over_k = true;
    rep(i, n) {
        if (s[i] == 0.0) is_zero = true;
        if (s[i] <= k) over_k = false;
    }

    if (is_zero) {
        cout << n << endl;
        return 0;
    }
    if (over_k && k >= 1.0) {
        cout << 0 << endl;
        return 0;
    }

    rep(i, n) s[i] = log(s[i]);
    k = log(k);

    vector<double> sum(n + 1, 0.0);
    rep(i, n) {
        sum[i + 1] = sum[i] + s[i];
    }

    auto copy = sum;

    for (int i = n - 1; i >= 0; --i) {
        chmin(copy[i], copy[i + 1]);
    }

    int ans = 0;
    rep(i, n) {
        chmax(ans, (int)(upper_bound(allof(copy), sum[i] + k) - copy.begin() - i - 1));
    }

    cout << ans << endl;

    return 0;
}

#include <algorithm>
#include <cmath>
#include <cstdint>
#include <cstdio>
#include <iomanip>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <vector>
using namespace std;
#define rep(i, n) for(int(i) = 0; (i) < (n); (i)++)
#define FOR(i, m, n) for(int(i) = (m); (i) < (n); (i)++)
#define All(v) (v).begin(), (v).end()
#define pb push_back
#define MP(a, b) make_pair((a), (b))
using ll = long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
const int INF = 1 << 30;
const ll LINF = 1LL << 60;
const int MOD = 1e9 + 7;

ll rec(int left, int right, vector<ll> &B, vector<vector<ll>> &dp) {
    if(left >= right)
        return 0;
    int l = left, r = right;
    if(dp[l][r] > 0)
        return dp[l][r];
    if(B[left] > B[right])
        left++;
    else
        right--;

    ll ret = max(rec(left + 1, right, B, dp) + B[left],
                 rec(left, right - 1, B, dp) + B[right]);
    return dp[l][r] = ret;
}

int main() {
    int N;
    cin >> N;
    vector<ll> A(N);
    rep(i, N) cin >> A[i];
    ll res = 0;
    vector<ll> B(2 * N);
    rep(i, 2 * N) B[i] = A[i % N];
    vector<vector<ll>> dp(4100, vector<ll>(4100, -1));

    for(int i = 0; i < N; i++) {
        res = max(rec(i + 1, N + i - 1, B, dp) + A[i], res);
    }
    cout << res << endl;
    return 0;
}

#include <bits/stdc++.h>
#pragma GCC target("avx2")
#pragma GCC optimization("O3")
#pragma GCC optimization("unroll-loops")
using namespace std;
using ll = long long;
using ld = long double;
const ll MOD = 998244353;
const ll root = 62;
ll gcd(ll a, ll b) { return b ? gcd(b, a % b) : a; }
ll binpow(ll a, ll b) {
  ll res = 1;
  while (b) {
    if (b & 1) res = (res * a) % MOD;
    a = (a * a) % MOD;
    b >>= 1;
  }
  return res;
}
ll modInv(ll a) { return binpow(a, MOD - 2); }
const double PI = acos(-1);
const double eps = 1e-10;
const int INF = 0x3f3f3f3f;
const int NINF = 0xc0c0c0c0;
const ll INFLL = 0x3f3f3f3f3f3f3f3f;
const ll NINFLL = 0xc0c0c0c0c0c0c0c0;
const int mxN = 2021;
int dp[mxN][mxN];
int dpprv[mxN][mxN];
int n, k;
ll ans = 0;
bool ok(vector<int> a) {
  if (accumulate(a.begin(), a.end(), 0) > n) return 0;
  vector<int> nxt;
  for (auto i = (0); i < (k - 1); ++i) {
    for (auto j = ((int)a.size()) - 1; j >= (0); --j) {
      for (auto b = (0); b < (a[j]); ++b) {
        nxt.push_back((int)a.size() - j);
      }
    }
    if (accumulate(nxt.begin(), nxt.end(), 0) > n) return 0;
    swap(nxt, a);
    nxt.clear();
  }
  return 1;
}
void solve(vector<int> &a) {
  if (!a.empty()) ans++;
  int nxt = a.empty() ? 1 : a.back();
  a.push_back(nxt);
  while (ok(a)) {
    solve(a);
    a.pop_back();
    a.push_back(++nxt);
  }
  a.pop_back();
}
int main() {
  mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());
  cin.tie(0)->sync_with_stdio(0);
  cin >> n >> k;
  if (k == 1) {
    dp[1][1] = 1;
    ans++;
    for (auto i = (2); i < (n + 1); ++i) {
      for (auto k = (1); k < (i + 1); ++k) {
        dp[i][k] = (dp[i - k][k] + dp[i - 1][k - 1]) % MOD;
        ans = (ans + dp[i][k]) % MOD;
      }
    }
    cout << ans << "\n";
    exit(0);
  } else if (k == 2) {
    for (auto i = (1); i < (n + 1); ++i) {
      for (auto j = (i); j < (n + 1); ++j) {
        dpprv[j][i] = 1;
      }
      ans++;
    }
    for (auto i = (2); i < (n + 1); ++i) {
      int mxj = n / i;
      for (auto j = (1); j < (mxj + 1); ++j) {
        for (auto k = (i * j); k < (n + 1); ++k) {
          dp[j][k] =
              (dpprv[n / (i - 1)][k - i * j] - dpprv[j - 1][k - i * j] + MOD) %
              MOD;
          ans = (ans + dp[j][k]) % MOD;
        }
      }
      for (auto j = (1); j < (mxj + 1); ++j) {
        for (auto k = (0); k < (n); ++k) {
          dpprv[j][k] = (dpprv[j - 1][k] + (k < i * j ? 0 : dp[j][k])) % MOD;
        }
      }
    }
    cout << ans << "\n";
    exit(0);
  }
  vector<int> geniosity = {};
  solve(geniosity);
  cout << ans << "\n";
  return 0;
}

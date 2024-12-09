#include <bits/stdc++.h>
using namespace std;
template <typename T>
void __read(T &a) {
  cin >> a;
}
template <typename T, typename... Args>
void __read(T &a, Args &...args) {
  cin >> a;
  __read(args...);
}
constexpr long long M7 = 1000000007ll;
constexpr long long M9 = 1000000009ll;
constexpr long long MFFT = 998244353ll;
template <class T>
void outv(T &a) {
  for (auto &x : a) cout << x << ' ';
}
static mt19937 rnd(static_cast<unsigned>(
    chrono::steady_clock::now().time_since_epoch().count()));
auto __fast_io__ = (ios_base::sync_with_stdio(false), cin.tie(nullptr));
int32_t main() {
  long long n, k;
  __read(n, k);
  vector<vector<long long>> a(n, vector<long long>(n, -1));
  for (long long i = 0; i < n; ++i) {
    for (long long j = i + 1; j < n; ++j) {
      cin >> a[i][j];
      a[j][i] = a[i][j];
    }
  }
  vector<vector<long double>> c(n + 1, vector<long double>(n + 1));
  for (long long i = 0; i <= n; ++i) {
    c[i][0] = c[i][i] = 1;
    for (long long j = 1; j < i; ++j) {
      c[i][j] = c[i - 1][j - 1] + c[i - 1][j];
    }
  }
  long double ans = 0;
  for (long long i = 0; i < n; ++i) {
    long double sm = 0;
    long long cnt = 0;
    for (long long j = 0; j < n; ++j) {
      if (a[i][j] != -1) {
        sm += a[i][j];
        cnt++;
      }
    }
    if (cnt >= k) {
      ans += c[cnt - 1][k - 1] * sm;
    }
  }
  cout << static_cast<long long>(ans / c[n][k]);
  return 0;
}

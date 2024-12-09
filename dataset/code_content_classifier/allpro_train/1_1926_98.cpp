#include <bits/stdc++.h>
using ll = long long;
constexpr ll mod = 1e9 + 7;
constexpr ll INF = 1LL << 60;
template <class T>
inline bool chmin(T &a, T b) {
  if (a > b) {
    a = b;
    return true;
  }
  return false;
}
template <class T>
inline bool chmax(T &a, T b) {
  if (a < b) {
    a = b;
    return true;
  }
  return false;
}
ll gcd(ll n, ll m) {
  ll tmp;
  while (m != 0) {
    tmp = n % m;
    n = m;
    m = tmp;
  }
  return n;
}
ll lcm(ll n, ll m) { return abs(n) / gcd(n, m) * abs(m); }
using namespace std;
void solve() {
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    vector<int> a(n + 5);
    for (int i = (int)0; i < (int)n; ++i) cin >> a[i];
    vector<int> pos(n + 5), last(n + 5, -1);
    for (int i = (int)0; i < (int)n; ++i) {
      chmax(pos[a[i]], i - last[a[i]]);
      last[a[i]] = i;
    }
    for (int i = (int)0; i < (int)n + 1; ++i) {
      chmax(pos[a[i]], n - last[a[i]]);
    }
    vector<int> cnt(n + 5, 5e5);
    for (int i = (int)0; i < (int)n + 1; ++i) {
      chmin(cnt[pos[i]], i);
    }
    vector<int> ans(n + 1);
    int res = 5e5;
    for (int i = (int)1; i < (int)n + 1; ++i) {
      chmin(res, cnt[i]);
      ans[i] = res != 5e5 ? res : -1;
    }
    for (int i = (int)0; i < (int)n; ++i) {
      if (i) cout << " ";
      cout << ans[i + 1];
    }
    cout << "\n";
  }
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout << fixed << setprecision(15);
  solve();
  return 0;
}

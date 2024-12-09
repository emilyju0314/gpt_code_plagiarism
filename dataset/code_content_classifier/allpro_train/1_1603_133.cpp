#include <bits/stdc++.h>
#pragma GCC target("avx2")
#pragma GCC optimization("O3")
#pragma GCC optimization("unroll-loops")
using namespace std;
const long long mod = 1e9 + 7;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
long long mul(long long a, long long b) { return ((a)*1ll * (b)) % mod; }
void add_self(long long& a, long long b) {
  a += b;
  if (a >= mod) a -= mod;
}
long long add(long long a, long long b) {
  long long c = a + b;
  if (c >= mod) {
    c -= mod;
  }
  return c;
}
long long sub(long long a, long long b) {
  a -= b;
  if (a < 0) {
    a += mod;
  }
  return a;
}
long long powz(long long a, long long b) {
  long long res = 1;
  while (b) {
    if (b & 1) {
      res = mul(res, a);
    }
    b /= 2;
    a = mul(a, a);
  }
  return res;
}
template <typename A, typename B>
istream& operator>>(istream& input, pair<A, B>& x) {
  input >> x.first >> x.second;
  return input;
}
template <typename A>
istream& operator>>(istream& input, vector<A>& x) {
  for (auto& i : x) input >> i;
  return input;
}
template <typename A>
ostream& operator<<(ostream& output, vector<A>& x) {
  for (auto& i : x) output << i << ' ';
  return output;
}
const long long N = 1000000;
void solve() {
  long long n;
  cin >> n;
  vector<long long> a(n), b(n);
  cin >> a >> b;
  vector<pair<long long, long long>> ans;
  for (long long i = 0; i < n; i++) {
    if (a[i] == b[i]) continue;
    for (long long j = i + 1; j < n; j++) {
      if (b[j] == a[i]) {
        long long k = j;
        while (k > i) {
          ans.push_back({k, k + 1});
          swap(b[k - 1], b[k]);
          k--;
        }
        break;
      }
    }
  }
  cout << ans.size() << "\n";
  for (auto i : ans) {
    cout << i.first << ' ' << i.second << "\n";
  }
}
signed main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  long long tc = 1;
  for (long long _ = 0; _ < tc; _++) {
    solve();
    if (_ != tc - 1) cout << "\n";
  }
}

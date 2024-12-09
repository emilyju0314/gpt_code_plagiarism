#include <bits/stdc++.h>
using namespace std;
template <typename T>
void ckmin(T &a, const T &b) {
  a = min(a, b);
}
template <typename T>
void ckmax(T &a, const T &b) {
  a = max(a, b);
}
long long gcd(long long a, long long b) { return b == 0 ? a : gcd(b, a % b); }
long long lcm(long long a, long long b) { return a / gcd(a, b) * b; }
void sieve(vector<int> &spf) {
  int n = spf.size();
  for (int i = (2); i < (n); i++) {
    if (!spf[i]) {
      ;
      for (int j = i; j < n; j += i) spf[j] = i;
    }
  }
}
long long int power(long long int x, long long int y,
                    long long int m = 998244353) {
  long long int ans = 1;
  x %= m;
  while (y) {
    if (y & 1) ans = (x * ans) % m;
    x = (x * x) % m;
    y >>= 1;
  }
  return ans;
}
long long int ncr(vector<int> &fact, int n, int r) {
  return (n >= r) ? (fact[n] *
                     (power(fact[r], 998244353 - 2) *
                      power(fact[n - r], 998244353 - 2) % 998244353) %
                     998244353)
                  : 0;
}
void solve() {
  int n;
  cin >> n;
  string s;
  vector<pair<int, int> > arr(n + 1);
  arr[0] = {0, 0};
  for (int i = (0); i < (n); i++) cin >> arr[i + 1].first >> arr[i + 1].second;
  sort((arr).begin(), (arr).end());
  for (int i = (1); i < (n + 1); i++) {
    int dx = arr[i].first - arr[i - 1].first,
        dy = arr[i].second - arr[i - 1].second;
    if (dx < 0 || dy < 0) {
      cout << "NO\n";
      return;
    }
    for (int i = (0); i < (dx); i++) s.push_back('R');
    for (int i = (0); i < (dy); i++) s.push_back('U');
  }
  cout << "YES\n" << s << "\n";
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int z = 1;
  cin >> z;
  while (z--) {
    solve();
  }
  return 0;
}

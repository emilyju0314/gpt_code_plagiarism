#include <bits/stdc++.h>
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#pragma GCC target("avx2")
using namespace std;
mt19937 rnd(chrono::steady_clock::now().time_since_epoch().count());
const int BUBEN = 400;
const int BUBEN3D = 2100;
const int BASE = 29;
const int MOD = (int)1e9 + 7;
char _getchar_nolock() { return getchar_unlocked(); }
inline int fasti() {
  int a = 0;
  char c = ' ';
  while (!isdigit(c)) {
    c = (char)_getchar_nolock();
  }
  while (isdigit(c)) {
    a = a * 10 + (c - '0');
    c = (char)_getchar_nolock();
  }
  return a;
}
long long gcd(long long a, long long b) {
  if (b == 0) {
    return a;
  }
  return gcd(b, a % b);
}
int bin_pow(int a, int n) {
  if (n == 0) {
    return 1;
  }
  if (n % 2 == 0) {
    int b = bin_pow(a, n / 2);
    return (long long)b * b % MOD;
  } else {
    return (long long)a * bin_pow(a, n - 1) % MOD;
  }
}
signed main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int t;
  cin >> t;
  while (t--) {
    int n, m;
    cin >> n >> m;
    vector<long long> arr(n);
    for (int i = 0; i < n; i++) {
      cin >> arr[i];
    }
    vector<vector<int>> graph(n);
    for (int i = 0; i < m; i++) {
      int a, b;
      cin >> a >> b;
      a--, b--;
      graph[b].push_back(a);
    }
    long long ans = 0;
    map<int, long long> mm;
    for (int i = 0; i < n; i++) {
      if (!graph[i].empty()) {
        int aa = 0;
        for (int to : graph[i]) {
          aa += bin_pow(BASE, to);
          aa %= MOD;
        }
        mm[aa] += arr[i];
      }
    }
    for (auto el : mm) {
      ans = gcd(el.second, ans);
    }
    cout << ans << '\n';
  }
  return 0;
}

#include <bits/stdc++.h>
using namespace std;
const long double pi = 3.14159265359;
inline long long add(long long a, long long b, long long m) {
  if ((a + b) >= m) return (a + b) % m;
  return a + b;
}
inline long long mul(long long a, long long b, long long m) {
  if ((a * b) < m) return a * b;
  return (a * b) % m;
}
long long power(long long x, long long y, long long m) {
  long long res = 1;
  x = x % m;
  if (x == 0) return 0;
  while (y > 0) {
    if (y & 1) res = (res * x) % m;
    y = y >> 1;
    x = (x * x) % m;
  }
  return res;
}
long long gcd(long long a, long long b) {
  if (b == 0) return a;
  return gcd(b, a % b);
}
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  long long int t = 1, n, m;
  cin >> t;
  while (t--) {
    cin >> n >> m;
    vector<long long> v(n);
    for (int i = 0; i < n; i++) cin >> v[i];
    if (m < n || n == 2) {
      cout << -1 << endl;
      continue;
    }
    vector<pair<int, int>> ans;
    long long s = 0;
    for (int i = 0; i < n; i++) {
      if (i == n - 1) {
        ans.push_back({i + 1, 1});
        s += v[i] + v[0];
      } else {
        ans.push_back({i + 1, i + 2});
        s += v[i] + v[i + 1];
      }
    }
    int f1 = INT_MAX, f2 = INT_MAX;
    int p1 = -1, p2 = -1;
    for (int i = 0; i < n; i++) {
      if (f1 == INT_MAX) {
        f1 = v[i];
        p1 = i;
      } else if (f2 == INT_MAX) {
        if (v[i] < f1) {
          f2 = f1;
          p2 = p1;
          f1 = v[i];
          p1 = i;
        } else {
          f2 = v[i];
          p2 = i;
        }
      } else if (v[i] < f1) {
        f2 = f1;
        p2 = p1;
        f1 = v[i];
        p1 = i;
      } else if (v[i] < f2) {
        f2 = v[i];
        p2 = i;
      }
    }
    for (int i = 0; i < m - n; i++) {
      s += v[p1] + v[p2];
      ans.push_back({p1 + 1, p2 + 1});
    }
    cout << s << endl;
    for (auto u : ans) {
      cout << u.first << " " << u.second << endl;
    }
  }
  return 0;
}

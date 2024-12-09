#include <bits/stdc++.h>
using namespace std;
void optimise() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
}
long long int mod = (long long int)1e9 + 7;
void normalize(long long int &a) { a = (a + mod) % mod; }
long long int modmul(long long int a, long long int b) {
  a = a % mod;
  b = b % mod;
  normalize(a);
  normalize(b);
  return (a * b) % mod;
}
long long int modadd(long long int a, long long int b) {
  a = a % mod;
  b = b % mod;
  normalize(a);
  normalize(b);
  return (a + b) % mod;
}
long long int modsub(long long int a, long long int b) {
  a = a % mod;
  b = b % mod;
  normalize(a);
  normalize(b);
  return (a - b + mod) % mod;
}
long long int me(long long int x, long long int n) {
  x %= mod;
  if (n == 0) return 1;
  long long int u = me(x, n / 2) % mod;
  u = (u * u) % mod;
  if (n % 2) u = (u * x) % mod;
  return u;
}
long long int me1(long long int x, long long int n) {
  if (n == 0) return 1;
  long long int u = me1(x, n / 2);
  u = u * u;
  if (n % 2) u = u * x;
  return u;
}
inline long long int modInv(long long int a) { return me(a, mod - 2); }
inline long long int modDiv(long long int a, long long int b) {
  return modmul(a, modInv(b));
}
float power(float x, long long int y) {
  float temp;
  if (y == 0) return 1;
  temp = power(x, y / 2);
  if (y % 2 == 0)
    return temp * temp;
  else {
    if (y > 0)
      return x * temp * temp;
    else
      return (temp * temp) / x;
  }
}
long long int __gcd(long long int a, long long int b) {
  if (b == 0)
    return a;
  else
    return __gcd(b, a % b);
}
pair<long long int, long long int> operator+(
    pair<long long int, long long int> a,
    pair<long long int, long long int> b) {
  return {a.first + b.first, a.second + b.second};
}
pair<long long int, long long int> operator-(
    pair<long long int, long long int> a,
    pair<long long int, long long int> b) {
  return {a.first - b.first, a.second - b.second};
}
pair<long long int, long long int> operator*(
    pair<long long int, long long int> a,
    pair<long long int, long long int> b) {
  return {a.first * b.first, a.second * b.second};
}
template <typename T>
ostream &operator<<(ostream &os, const set<T> &v) {
  for (auto it : v) os << it << " ";
  return os;
}
template <typename T>
ostream &operator<<(ostream &os, const vector<T> &v) {
  for (long long int i = 0; i < v.size(); ++i) os << v[i] << " ";
  return os;
}
template <typename T>
void Unique(vector<T> &v) {
  sort(v.begin(), v.end()),
      v.resize(distance(v.begin(), unique(v.begin(), v.end())));
}
void solve() {
  long long int n;
  cin >> n;
  vector<long long int> v(n + 1, 0);
  long long int flag = 0;
  vector<long long int> vis(n + 1, 0);
  for (long long int i = 0; i < n - 1; i++) {
    long long int x, y;
    cin >> x >> y;
    if (y != n) flag = 1;
    v[x]++;
    v[y]++;
  }
  if (flag) {
    cout << "NO";
    return;
  }
  vector<pair<long long int, long long int> > ans;
  for (long long int i = 1; i < n; i++) {
    if (v[i] >= 1) {
      long long int k = 0;
      for (long long int j = 1; j < i; j++) {
        if (vis[j] == 0) k++;
      }
      if (k >= (v[i] - 1)) {
        long long int k1 = n;
        for (long long int j = 1; j < i; j++) {
          if (v[i] > 1 and vis[j] == 0) {
            vis[j] = 1;
            ans.push_back({k1, j});
            k1 = j;
            v[i]--;
          }
        }
        ans.push_back({k1, i});
        vis[i] = 1;
      } else {
        cout << "NO";
        return;
      }
    }
  }
  cout << "YES"
       << "\n";
  for (auto y : ans) cout << y.first << " " << y.second << "\n";
}
signed main() {
  optimise();
  long long int t;
  t = 1;
  cout << fixed << setprecision(20);
  while (t--) {
    solve();
    cout << "\n";
  }
}

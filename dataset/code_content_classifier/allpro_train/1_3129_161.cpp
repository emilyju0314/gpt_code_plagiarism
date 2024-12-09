#include <bits/stdc++.h>
using namespace std;
template <typename T>
void print(const T& v) {
  cerr << v << ' ';
}
template <typename T1, typename... T2>
void print(const T1& first, const T2&... rest) {
  print(first);
  print(rest...);
}
typedef priority_queue<pair<int, int>, vector<pair<int, int> >,
                       greater<pair<int, int> > >
    pq;
int setbit(int N, int pos) { return N = N | (1 << pos); }
int resetbit(int N, int pos) { return N = N & ~(1 << pos); }
bool checkbit(int N, int pos) { return (bool)(N & (1 << pos)); }
int nextN(int N) { return N + (N & (-N)); }
int parentN(int N) { return N - (N & (-N)); }
template <typename T>
T extGcd(T a, T b, T& x, T& y) {
  if (a == 0) {
    x = 0, y = 1;
    return b;
  }
  T x1, y1, gcd = extGcd(b % a, a, &x1, &y1);
  x = y1 - (b / a) * x1, y = x1;
  return gcd;
}
template <typename T>
T bigMod(T a, T p, T m) {
  if (p == 1) return a;
  T x = bigMod(a, p / 2, m) % m;
  x = (x * x) % m;
  return (p & 1) ? (x * a) % m : x;
}
template <typename T>
T modMul(T a, T b, T m) {
  return ((a % m) * (b % m)) % m;
}
template <typename T>
T modAdd(T a, T b, T m) {
  return ((a % m) + (b % m)) % m;
}
template <typename T>
T modSub(T a, T b, T m) {
  return (a - b + m) % m;
}
template <typename T>
T modInverse(T a, T m) {
  return bigMod(a, m - 2, m);
}
void solve() {
  int n;
  string s;
  cin >> n >> s;
  int ans[n], clr[27], a[n + 1][27];
  memset(clr, -1, sizeof clr);
  memset(ans, -1, sizeof ans);
  for (int i = n - 1; i >= 0; --i) {
    if (i == n - 1)
      for (int j = 0; j <= 25; ++j) a[i][j] = 0;
    else {
      for (int j = 0; j <= 25; ++j) a[i][j] = a[i + 1][j];
      a[i][s[i + 1] - 'a'] = 1;
    }
  }
  set<int> cnt;
  for (int i = 0; i <= n - 1; ++i) {
    int c = s[i] - 'a', used = 0;
    if (clr[c] == -1) {
      ans[i] = 0;
      clr[c] = 0;
      used = 1;
    } else
      ans[i] = clr[c];
    for (int j = 0; j <= c - 1; ++j) {
      if (a[i][j] == 0) continue;
      if (clr[j] == -1) clr[j] = 0;
      if (clr[c] == clr[j]) clr[j]++;
    }
    if (used == 1) clr[c] = -1;
    cnt.insert(ans[i]);
  }
  cout << (int)cnt.size() << endl;
  for (int i = 0; i <= n - 1; ++i) cout << ans[i] + 1 << " ";
}
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  ;
  int t = 1, tc = 0;
  while (t--) {
    solve();
  }
  return 0;
}
